#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
        int pid;
        printf("\nI am a process with pid %d\n", (int)getpid());
        pid=fork();
        if(pid<0)
        {
                perror("Fork failed\n");
        }
        if(pid==0)
        {
                printf("I'm the child process with pid %d\n", (int)getpid());
		exit(0);
        }
	printf("I'm the parent process with pid %d\n", (int)getpid());
}

