#include<stdio.h>
#include<sys/types.h>
void main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
		printf("\nChild creation unsuccessfull\n");
	else if(pid==0)
		printf("\nChild process Created, pid:\t%d\n",getpid());
	else
		printf("\nParent process created, pid=\t%d\n",getpid());
}
