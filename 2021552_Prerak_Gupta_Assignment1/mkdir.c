#include<curses.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[]){
	
	int d=mkdir(argv[1],0777);
	if(!d){
		printf("Directory created\n");
	}
	else{
		printf("Unable to create directory\n");
		exit(1);
	}

	/*else if(argc==2){
		if(strcmp(argv[1],"-p")==0){
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
				exit(1);
			}
		}
	}*/
	return 0;
}
