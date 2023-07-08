#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char* argv[]){
	struct dirent *d;
	DIR* dr=opendir(".");
	char* str[100];
	int co=0;
	while((d=readdir(dr))!=NULL){
		if(d->d_name[0]=='.')
			continue;
		//printf("%s ",d->d_name);
		str[co]=d->d_name;
		co++;
	}
	printf("Directories are :- \n");
	char temp[100];
	for(int i=0;i<co;i++){
		for(int j=i+1;j<co;j++){
			if(strcmp(str[i],str[j])>0){
				strcpy(temp,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
		}
	}
	for(int i=0;i<co;i++){
		printf("%s  ",str[i]);
	}
	printf("\n");
	return 0;
}
