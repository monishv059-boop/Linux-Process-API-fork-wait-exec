#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("Child process executing ls command\n");
        execlp("ls", "ls", NULL);

        // If exec fails
        perror("Exec failed");
        exit(1);
    }
    else
    {
        // Parent process
        wait(NULL);
        printf("Parent process: Child execution completed\n");
    }

    return 0;
}
