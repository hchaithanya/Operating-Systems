#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>    
main() 
{ 
	int shmid, status; 
        int *a, *b; 
        int i,n; 
	shmid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT); 
	if (fork() != 0) 
	{
		printf("Enter an integer : ");
    		scanf("%d",&n);
		a = (int *) shmat(shmid, 0, 0); 
		a[0]=n;
		wait(&status);
                shmdt(a); 
	    	shmctl(shmid, IPC_RMID, 0); 
        	
        } 
        else 
	{ 
		sleep(2);
		b = (int *) shmat(shmid, 0, 0); 
		printf("The odd numbers are : ");
        	for (i=1 ; i <= b[0] ; i=i+2) 
		{
            		printf("%d ", i);
       	        }
                             
                shmdt(b); 	
	} 
} 


