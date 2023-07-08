#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char* argv[]){
	if(strcmp(argv[1],"-p")==0){
		char cs[100];
		int j=0;
		for(int i=0;i<strlen(argv[2]);i++){
			if(argv[2][i]=='/'){
				cs[j]='\0';
				j=0;
				mkdir(cs,0777);
				chdir(cs);
			}
			else if(i==strlen(argv[2])-1){
				cs[j]=argv[2][i];
				cs[j+1]='\0';
				mkdir(cs,0777);
			}	
			else{
				cs[j]=argv[2][i];
				j++;
			}
		}
		mkdir(argv[2],0777);
	}
	else if(strcmp(argv[1],"-v")==0){
		int d=mkdir(argv[2],0777);
		if(!d){
			printf("Creating directory \n");
			printf("Directory created successfully\n");
		}
		else{
			printf("Unable to create directory\n");
			printf("Directory already exist\n");
		}
	}
	else{
		printf("Invalid Command\n");
	}
	return 0;
}
