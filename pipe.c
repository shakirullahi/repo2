#include<stdio.h>
#include<sys/types.h>
#include<string.h>
void main()
{
	int r,pfd[2],t=0;	
	pid_t pid;
	char buff[20],buff1[20];
	r=pipe(pfd);
	printf("\nEnter input:\t\n");
	scanf("%s",buff);
	pid=fork();
	if(pid<0)
		printf("\nChild creation unsuccessfull\n");
	else if(pid==0)
	{

		printf("\nChild process Created, pid:\t%d\n",getpid());
		write(pfd[1],buff,sizeof(buff));		
		printf("\nThe writed data to child process is :\t%s\n",buff);
		printf("\nT=:\t%d\n",t);
	}
	else
	{
		printf("\nParent process created, pid=\t%d\n",getpid());
		read(pfd[0],buff,sizeof(buff));
		strcpy(buff,"too");
		t=1;
		
	}
}
