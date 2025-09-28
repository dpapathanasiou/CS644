import subprocess

ls_thread = subprocess.Popen(["ls", "-l"], stdout=subprocess.PIPE, text=True)
grep_thread = subprocess.Popen(["grep", "md"], stdin=ls_thread.stdout, stdout=subprocess.PIPE, text=True)

stdout, stderr = grep_thread.communicate()

print(f'Trying:\n\nls -l | grep *.md\n\n** stdout:\n{stdout}\n** stderr: {stderr}')
