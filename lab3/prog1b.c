#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	int pid;

        printf("\nI am a process with pid %d\n", (int)getpid());
	pid=fork();

	printf("\nFork returned %d\n",pid);
	printf("\nI am a process with pid %d\n", (int)getpid());
}
