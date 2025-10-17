#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define PORT 5000
#define BACKLOG 10

// Structure to pass data to thread function
typedef struct
{
    int client_fd;
    struct sockaddr_in client_addr;
} client_data_t;

// Thread function to handle each client
void *handle_client(void *arg)
{
    client_data_t *client_data = (client_data_t *)arg;
    int client_fd = client_data->client_fd;
    struct sockaddr_in client_addr = client_data->client_addr;
    char buffer[BUFSIZ];

    // Print connection information
    printf("Thread handling client %s:%d\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Send welcome message to client
    const char *welcome_msg = "Hello from threaded server!\n";
    send(client_fd, welcome_msg, strlen(welcome_msg), 0);

    // Handle client communication
    while (1)
    {
        int bytes_read = read(client_fd, buffer, BUFSIZ - 1);
        if (bytes_read <= 0)
        {
            // Client disconnected or error
            break;
        }

        buffer[bytes_read] = '\0';
        printf("Received from client %s:%d: %s",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);

        // Echo the message back to client
        send(client_fd, buffer, bytes_read, 0);
    }

    printf("Client %s:%d disconnected\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Clean up
    close(client_fd);
    free(client_data);
    pthread_exit(NULL);
}

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    int opt = 1;
    pthread_t thread_id;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, BACKLOG) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Threaded server listening on port %d\n", PORT);

    while (1)
    {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address,
                                &addrlen)) < 0)
        {
            perror("accept failed");
            continue;
        }

        // Create client data structure
        client_data_t *client_data = malloc(sizeof(client_data_t));
        if (client_data == NULL)
        {
            perror("malloc failed");
            close(client_fd);
            continue;
        }

        client_data->client_fd = client_fd;
        client_data->client_addr = address;

        // Create new thread to handle client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client_data) != 0)
        {
            perror("pthread_create failed");
            free(client_data);
            close(client_fd);
            continue;
        }

        // Detach thread so it cleans up automatically when finished
        pthread_detach(thread_id);

        printf("New client connected, assigned thread ID: %lu\n", thread_id);
    }

    // Close server socket (this won't be reached in this example)
    close(server_fd);
    return 0;
}