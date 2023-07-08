#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

void ls_fun(char* dn,int a,int l){
	struct dirent *d;
	DIR *dr=opendir(dn);
	if(!dr){
		if(errno=ENOENT){
			printf("Directory doesn't exist\n");
		}
		else{
			printf("Unable to read directory\n");
		}
		exit(EXIT_FAILURE);
	}
	else{
		char* str[100],temp[100];
		int co=0;
		while((d=readdir(dr))!=NULL){
			if(!a && d->d_name[0]=='.'){
				continue;
			}
			//printf("%s   ",d->d_name);
			str[co]=d->d_name;
			co++;
			if(l){
				//printf("\n");
			}
		}
		for(int i=0;i<=co;i++){
			for(int j=i+1;j<=co;j++){
				if(strcmp(str[i],str[j])>0){
					strcpy(temp,str[i]);
					strcpy(str[i],str[j]);
					strcpy(str[j],temp);
				}
			}
		}
		if(!l){
			//printf("\n");
		}
		if(l==1){
			for(int k=0;k<=co;k++){
				printf("%s\n",str[k]);
			}
		}
		else {
			for(int k=0;k<=co;k++){
				printf("%s   ",str[k]);
			}
			printf("\n");
		}
	}	
}

int main(int argc,char* argv[]){
			int _a=0;
			int _l=0;
			char* p=(char*)(argv[1]+1);
			while(*p){
				if(*p=='a') _a=1;
				else if(*p=='1') _l=1;
				else{
					printf("Invalid option\n");
					exit(EXIT_FAILURE);
				}
				p++;
			}
printf("Directories are :- \n");
			//ls_fun(".",_a,_l);
	struct dirent *d;
	DIR *dr=opendir(".");
	if(!dr){
		if(errno=ENOENT){
			printf("Directory doesn't exist\n");
		}
		else{
			printf("Unable to read directory\n");
		}
		exit(EXIT_FAILURE);
	}
	else{
		char* str[100],temp[100];
		int co=0;
		while((d=readdir(dr))!=NULL){
			//printf("%s   ",d->d_name);
			str[co]=d->d_name;
			co++;
		}
		for(int i=0;i<=co;i++){
			for(int j=i+1;j<=co;j++){
				if(strcmp(str[i],str[j])>0){
					strcpy(temp,str[i]);
					strcpy(str[i],str[j]);
					strcpy(str[j],temp);
				}
			}
		}
			for(int k=0;k<=co;k++){
				printf("%s   ",str[k]);
			}
			printf("\n");
	}	
	return 0;
}
