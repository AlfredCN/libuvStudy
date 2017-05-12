#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	pid_t child;
	if((child = fork())==-1){
		printf("fock\n");
		exit(EXIT_FAILURE);
	}
	else if(child == 0){
		printf("in child\n");
		printf("\t child pid = %d \n",getpid());
		printf("\t child ppid = %d \n",getppid());
		exit(EXIT_SUCCESS);
	}
	else{
		puts("in parent");
		printf("\t parent pid = %d \n",getpid());
		printf("\t parent ppid = %d \n",getppid());
	}
	exit(EXIT_SUCCESS);
}
