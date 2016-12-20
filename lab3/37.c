#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
    int childpid;
    int count1=0,count2=0;
    char p=65;
    printf("Before it forks!!\n");
    childpid=fork();
    if(childpid==0)
    {

        while(count1<5)
        {
            printf("This is a child process with pid %d\n",(int)getppid());
            printf("Child process: %c\n",p);
            sleep(1);
            count1++;
            p++;
        }
    }
    else
    {

        while(count2<3)
        {
            printf("This is a parent process with pid %d\n",(int)getpid());
            printf("Parent process: %c\n",p);
            sleep(1);
            count2++;
            p++;
        }
    }
