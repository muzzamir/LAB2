#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void child(){
        char name[30];
        printf("Enter name : ");
        fgets(name, sizeof(name), stdin);
        printf("\nMy name is : ");
        puts(name);
        printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
        exit(0);
        }

void parent(){
        printf("Parent process => PID=%d\n", getpid());
        printf("All child process finished.\n");
        printf("Job is done");
        }

void waiting(){
        printf("Parent process => PID=%d\n", getpid());
        printf("Waiting for child processes to finish...\n");
        wait(NULL);
        printf("child process finished.\n");
        }

int main(){
        for(int i = 1; i <= 4; i++){
                pid_t pid = fork();
                if(pid == 0){
                        child();
                }else if(i == 4){
                        waiting();
                        parent();
                }else waiting();
        }
        return EXIT_SUCCESS;
}
