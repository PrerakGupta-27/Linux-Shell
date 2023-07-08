#include<time.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char* argv[]){
	if(argc==3 && strcmp(argv[1],"-r")==0){
		char fname[100];
		strcpy(fname,argv[2]);
		char ft[100];
		struct stat st;
		if(!stat(fname,&st)){
			strftime(ft,100,"%d/%m/%Y %H:%M:%S\n",localtime(&st.st_mtime));
			printf("Last modified date and time is %s\n",ft);
		}
		else{
			printf("Error :- can;t display date and time \n");
		}
	}
	else{
		printf("Error:- Invalid command\n");
	}
	return 0;
}
