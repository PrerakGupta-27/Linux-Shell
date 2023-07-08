#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

int main(int argc,char* argv[]){
	struct dirent* d;
	DIR* dr=opendir(".");
	char* str[100];
	char temp[100];
	int co=0;
	while((d=readdir(dr))!=NULL){
		if(d->d_name[0]=='.')
			continue;
		str[co]=d->d_name;
		co++;
	}
	for(int i=0;i<co;i++){
		for(int j=i+1;j<co;j++){
			if(strcmp(str[i],str[j])>0){
				strcpy(temp,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
		}
	}
	for(int k=0;k<co;k++){
		printf("%s\n",str[k]);
	}
	return 0;
}
