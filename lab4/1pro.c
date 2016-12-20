#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16

main()
{
	int integer,a,i;
	int p[2],j;
	pid_t pid;

	if(pipe(p)== -1)
	{
		perror("pipe call");
		exit(1);
		}

	switch(pid=fork())
	{
	case -1:
		perror("fork failed");
		exit(2);
	
	case 0:
		
		close(p[1]);
		read(p[0],&a,sizeof(a));
			for(i=0;i<a;i++)
			{
				if(i%2!=0)
				{
					printf("Odd numbers are %d \n", i);
				}
			}
		close(p[0]);
		break;

	default:
		printf("Enter the integer ");
		scanf("%d",&integer);
		close(p[0]);
		write(p[1],&integer,sizeof(integer));
		close(p[1]);
	
		//wait(NULL);
	}
}
	
