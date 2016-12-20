#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MSGSIZE 16

main()
{
	int i;
	char inbuf[MSGSIZE],msg;
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
		read(p[0],inbuf,MSGSIZE);
		for(i=0;i<strlen(inbuf);i++)
		{
			inbuf[i]=inbuf[i]-32;
			
		}
		printf("%s \n",inbuf);
		close(p[0]);
		break;

	default:
		printf("Enter the string ");
		scanf("%s",&msg);
		close(p[0]);
		write(p[1],&msg,MSGSIZE);
		close(p[1]);
	
		
	}
	
	exit(0);
}





