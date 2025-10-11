#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5000

void handle_client(int client_socket)
{
    char buffer[BUFSIZ];
    int bytes_read;
    while ((bytes_read = read(client_socket, buffer, BUFSIZ)) > 0)
    {
        // Echo the received message back to the client
        write(client_socket, buffer, bytes_read);
    }
    close(client_socket);
}

void start()
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0)
    {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept and handle incoming connections
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) >= 0)
    {
        printf("Connected to client (%d:%d)\n", client_addr.sin_addr.s_addr, client_addr.sin_port);

        // Handle the client in a separate function
        handle_client(client_socket);
        printf("Client (%d:%d) disconnected\n", client_addr.sin_addr.s_addr, client_addr.sin_port);
    }

    // will never get here, but for completeness
    close(server_socket);
}

int main()
{
    start();
    return EXIT_SUCCESS;
};