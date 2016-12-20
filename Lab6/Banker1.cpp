#include<iostream>
using namespace std;
int main()
{
int instance[5],count,sequence[10],safe,s=0,j,completed;
int available[5],allocation[10][5],max[10][5];
int need[10][5],process,P[10],resource_count,process_count,running[10];
resource_count=3;
for(int i=0;i<resource_count;i++)
{  cout<<"\n enter the max instances of  resource R["<<i<<"] :";
   cin>>instance[i];
   available[i]=instance[i];
}
cout<<"\n Enter the number of processes: ";
cin>> process_count;
cout<<"\n Enter the allocation matrix \n     ";

for(int i=0 ; i<process_count ; i++)
   {
   cout<<"FOR THE PROCESS :P["<<i<<"]"<<endl;
    for(int j=0;j<resource_count;j++)
    {  cout<<"allocation of resource R["<<j<<"] is : " ;
   cin>>allocation[i][j];
   available[j]-=allocation[i][j];
 }
   }
cout<<"\nEnter the MAX matrix \n\n";

    for(int i=0;i<process_count;i++)
       { cout<<"FOR THE PROCESS P["<<i<<"]"<<endl;
 for(int j=0;j<resource_count;j++)
  {   cout<<"max demand of resource R["<<j<<"] is : ";
      cin>>max[i][j];
  }
       }
cout<<"\n the given data are : \n";

cout<<endl<<"\nTotal resources in system : \n\n  ";
for(int i=0;i<resource_count;i++)
   cout<<" R["<<i<<"]  ";
   cout<<endl;
for(int i=0;i<resource_count;i++)
   cout<<"     "<<instance[i];

cout<<"\n\n ALLOCATION matrix \n\n\t";
for(j=0;j<resource_count;j++)
   cout<<"R["<<j<<"]  ";
   cout<<endl;

for( int i=0;i<process_count;i++)
{  cout<<"P["<<i<<"]  ";
   for(j=0;j<resource_count;j++)
      cout<<"    "<<allocation[i][j];
   cout<<endl;
 }

 cout<<"\n\n MAX matrix \n\n\t";
for(j=0;j<resource_count;j++)
   cout<<"R["<<j<<"]  ";
   cout<<endl;

for(int i=0;i<process_count;i++)
{  cout<<"P["<<i<<"]  ";
   for(j=0;j<resource_count;j++)
      cout<<"    "<<max[i][j];
   cout<<endl;
 }
    for( int i=0;i<process_count;i++)
       {
 for(j=0;j<resource_count;j++)
  {
      need[i][j]=max[i][j]-allocation[i][j];
  }
 }

 cout<<"\n\n NEED matrix \n\n\t";
for(j=0;j<resource_count;j++)
   cout<<"R["<<j<<"]  ";
   cout<<endl;

for(int i=0;i<process_count;i++)
{  cout<<"P["<<i<<"]  ";
   for(j=0;j<resource_count;j++)
      cout<<"    "<<need[i][j];
   cout<<endl;
 }

 cout<<"\n NOW to  check whether above state is safe";
 cout<<"\n sequence in which above requests can be fulfilled";
 cout<<"\n press any key to continue";

count=process_count;

for(int i=0;i<process_count;i++)
    { running[i]=1;}

while(count)
    {   safe=0;
        for(int i=0;i<process_count;i++)
   { if(running[i])
       {  completed=1;
   for(j=0;j<resource_count;j++)
      {   if(need[i][j]> available[j])
     { completed=0;
       break;
     }
      }
  if(completed)
                {
     running[i]=0;
                    count--;
     safe=1;
                    for(j=0;j<resource_count;j++)
                    {
                        available[j]+=allocation[i][j];
                    }
     sequence[s++]=i;
     cout<<"\n\n Running process P["<<i<<"]";
     cout<<endl<<"\n\nTotal resources now available:\n\n";
     for(int i=0;i<resource_count;i++)
     cout<<" R["<<i<<"]  ";
     cout<<endl;
     for(int i=0;i<resource_count;i++)
     cout<<"     "<<available[i];
                    break;
                }
            }

        }
         if(!safe)
         break;
     }

 if(safe)
  {
            cout<<"\nThe System is in safe state";
    cout<<"\nSafe sequence is :";
            for(int i=0;i<process_count;i++)
            {
                cout<<"\t"<<"P["<<sequence[i]<<"]";
            }
  }
 else
  {
    cout<<"\nThe System is in unsafe state";
  }
}
