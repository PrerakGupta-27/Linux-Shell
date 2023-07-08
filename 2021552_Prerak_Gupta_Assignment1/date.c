#include<stdio.h>
#include<time.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char* argv[]){
	if(argc==1){
		char ctime[100];
		time_t ti=time(NULL);
		struct tm* t=localtime(&ti);
		strftime(ctime,100,"%a %b %d %H:%M:%S IST %Y\n",t);
		printf("%s",ctime);
	}
	else if(argc==2){
		if(strcmp(argv[1],"-u")==0){
			time_t t= time(&t);
			if(t==-1){
				printf("Error\n");
			}
			struct tm* tm =gmtime(&t);
			if(tm==NULL){
				printf("Error\n");
			}
			printf("UTC time %s\n",asctime(tm));
		}
	}
	else if(argc==3 && strcmp(argv[1],"-r")==0){
		char fname[100];
		strcpy(fname,argv[2]);
		char ft[100];
		struct stat fil;
		if(!stat(fname,&fil)){
			strftime(ft,100,"%d/%m/%Y %H:%M:%S",localtime(&fil.st_mtime));
			printf("Last modified time is %s\n",ft);
		}
		else{
			printf("Error \n");
		}
	}
	else{
		printf("Error :- Invalid command\n");
	}
	return 0;
}
