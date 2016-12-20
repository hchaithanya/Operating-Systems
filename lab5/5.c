#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>  
void main()
{
	int shmid, status; 
    char *a, *b,*c; 
    int i,x; 
    int p2,p3;
    shmid = shmget(IPC_PRIVATE, 100*sizeof(char), 0777|IPC_CREAT); 
p2 = fork();
if(p2==0)
{
p3=fork();
if(p3==0)
{
printf("process C-%d\n",(int)getpid());
char *k;
c = (char *) shmat(shmid, 0,0);
gets(k);
strcat(c,l);
puts(c);
shmdt(c); 
}
else if(p3>0)
{
printf("process B-%d\n",(int)getpid());	
char *l;
b = (char *) shmat(shmid, 0,0);
gets(l);
strcat(b,l);
puts(b);
shmdt(b); 
}
}
else if(p2>0)
{
printf("process A-%d\n",(int)getpid());
a = (char *) shmat(shmid, 0,0);
gets(a);
sleep(15);
puts(a);
wait(&status); 
shmdt(a); 
shmctl(shmid, IPC_RMID, 0); 
}
}
