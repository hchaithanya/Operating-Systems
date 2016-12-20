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
		printf("I'm  child process with pid %d\n", (int)getpid());
	}
	else if(pid>0)
	{
		printf("I'm process with pid %d\n", (int)getpid());
	}
}

