#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

void main(){
	int cpid,val=0,pipe1[2],final=0;
	pipe(pipe1);
	for(int i=0;i<1000;i=i+100){
		cpid = fork();
		if(cpid == 0){
			int sum =0;
			for(int j=i;j<i+100;v++){
				sum = sum + j;
			}
			write(pipe1[1],&sum,sizeof(sum));
			exit(0);							
		}
		wait(NULL);
		read(pipe1[0],&val,sizeof(val));
		final = final + val;
	}
	printf("Sum is : %d",final);
	
}
