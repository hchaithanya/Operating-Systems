#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{

printf("\nI am a process with pid %d\n", (int)getpid());
}
