#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <string.h>    
main() 
{ 
        int shmid, status; 
        int *a, *b; 
        int i; 
	char str[10];
    	printf("Enter a string: ");
    	getchar(str);	
	shmid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT); 
	if (fork() == 0) 
	{
		b = (char *) shmat(shmid, 0, 0); 
		printf("The string in capital letters :");
        	for(i=0 ; i < strlen(str) ; i++) 
		{
            		if(b[i]>= 97 && b[i]<=122)
                	{
				printf("%c",b[i]-32);
			}
            		else
                 	{
				printf("%c",b[i]);
		        }
		}                             
                shmdt(b); 
        } 
        else 
	{ 
		
		a = (char *) shmat(shmid, 0, 0);
        	for(i=0 ; i< strlen(str) ; i++)
            		a[i] = str[i];
       		wait(&status);
        	shmdt(a);
        	shmctl(shmid, IPC_RMID, 0);
	    	
        } 
} 


