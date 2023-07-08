#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>
#include<stdbool.h>
#include<pthread.h>
void thread_func(char* com,char* args[10]){
	pthread_t thid;
	char* arg=malloc(100);
	strcpy(arg,com);
	for(int i=1;i<10;i++){
		if(args[i]!=NULL && strcmp(args[i],"&t")!=0){
			strcat(arg," ");
			strcat(arg,args[i]);
		}
		else{
			break;
		}
	}
	pthread_create(&thid,NULL,(void *)system,arg);
	pthread_join(thid,NULL);
}

void command_cd_func(char* str){
	int a;
	char dir_path[100];
	if(strcmp(str,".")==0){
		getcwd(dir_path,sizeof(dir_path));
		strcat(dir_path,"/");
		strcat(dir_path,str);
		a=chdir("dir_path");
	}
	else if(strcmp(str,"..")==0){
		a=chdir("..");
	}
	else if(strcmp(str,"~")==0){
		str++;
		char* cp=getenv("HOME");
		strcat(cp,str);
		a=chdir(cp);
	}
	else{
		a=chdir(str);
	}
	if(a==-1){
		printf("Invalid Path\n");
	}
	else{
		char sr[100];
		printf("Current directory after changing directory is %s\n",getcwd(sr,100));
	}
}

void command_echo_func(char* words[],int count){
	if(strcmp(words[1],"-n")==0){
		for(int i=2;i<count;i++){
			int j=0;
			while(j!=strlen(words[i])){
				if(words[i][j]=='\n'){
				}
				else{
					printf("%c",words[i][j]);
				}
				j++;
			}
			if(i!=count-1){
				printf(" ");
			}
		}	
	}
	else if(strcmp(words[1],"-E")==0){
		for(int i=2;i<count;i++){
			int j=0;
			while(j!=strlen(words[i])){
				if(words[i][j]=='\\' || words[i][j]=='\n'){
				}
				else{
					printf("%c",words[i][j]);
				}
				j++;
			}
			printf(" ");
		}
		printf("\n");

	}
	else{
		for(int i=1;i<count;i++){
			int j=0;
			while(j!=strlen(words[i])){
				if(words[i][j]=='\\' || words[i][j]=='\n'){
				}
				else{
					printf("%c",words[i][j]);
				}
				j++;
			}
			printf(" ");
		}
		printf("\n");
	}
}

void command_rm_func(char* words[],int count){
	pid_t pfid = fork();
	if(pfid==0){
		//printf("Inside child %d\n",getpid());
		if(count==2){
			execl("./rm",words[0],words[1],NULL);
			exit(0);
		}
		else if(count==3){
			execl("./rm",words[0],words[1],words[2],NULL);
			exit(0);
		}
		else{
			printf("Invalid command\n");
		}
	}
	else if(pfid>0){
		//printf("Inside parent %d\n",getpid());
		int status;
		wait(&status);
		//printf("Child is reaped\n");
	}
	else{
		printf("Error :- Unable to fork\n");
		exit(EXIT_FAILURE);
	}
}

void command_cat_func(char* words[],int count){
	pid_t pfid = fork();
	if(pfid==0){
		//printf("Inside child %d\n",getpid());
		if(count==2){
			execl("./cat",words[0],words[1],NULL);
			exit(0);
		}
		else if(count==3){
			execl("./cat",words[0],words[1],words[2],NULL);
			exit(0);
		}
		else{
			printf("Invalid command Check number of arguments \n");
		}
	}
	else if(pfid>0){
		//printf("Inside parent %d\n",getpid());
		int status;
		wait(&status);
		//printf("Child is reaped\n");
	}
	else{
		printf("Error :- Unable to fork\n");
		exit(EXIT_FAILURE);
	}
}

void command_date_func(char* words[],int count){
	pid_t pfid=fork();
	if(pfid==0){
		//printf("Inside child %d\n",getpid());
		if(count ==1){
			execl("./date",words[0],NULL);
			exit(0);
		}
		else if(count==2){
			execl("./date",words[0],words[1],NULL);
			exit(0);
		}
		else if(count==3){
			execl("./date2",words[0],words[1],words[2],NULL);
			exit(0);			
		}
		else{
			printf("Invalid command check number of arguments\n");
		}
	}
	else if(pfid>0){
		//printf("Inside parent %d\n",getpid());
		int status;
		wait(&status);
		//printf("Child is reaped\n");
	}
	else{
		printf("Error :- Unable to fork\n");
		exit(EXIT_FAILURE);
	}
}

void command_ls_func(char* words[],int count){
	pid_t pfid=fork();
	if(pfid==0){
		//printf("Inside child %d\n",getpid());
		if(count==1){
			execl("./ls1",words[0],NULL);
			exit(0);
		} 
		else if(count==2){
			if(strcmp(words[1],"-a")==0){
				execl("./ls",words[0],words[1],NULL);
				exit(0);
			}
			else{
				execl("./ls2",words[0],words[1],NULL);
			}
		}
		else{
			printf("Invalid command check number of arguments\n");
		}
	}
	else if(pfid>0){
		//printf("Inside parent %d\n",getpid());
		int status;
		wait(&status);
		//printf("Child is reaped\n");
	}
	else{
		printf("Error :- Unable to fork\n");
		exit(EXIT_FAILURE);
	}
}

void command_mkdir_func(char* words[],int count){
	pid_t pfid=fork();
	if(pfid==0){
		//printf("Inside child %d\n",getpid());
		if(count==2){
			execl("./mkdir",words[0],words[1],NULL);
			exit(0);
		}
		else if(count==3){
			execl("./mkdir2",words[0],words[1],words[2],NULL);
			exit(0);
		}
		else{
			printf("Invalid command check number of arguments\n");
		}
	}
	else if(pfid>0){
		//printf("Inside parent %d\n",getpid());
		int status;
		wait(&status);
		//printf("Child is reaped\n");
	}
	else{
		printf("Error :- Unable to fork\n");
		exit(EXIT_FAILURE);
	}
}

void command_pwd_func(char* words[],int count){
	if(count==1){
		char s[100];
		printf("%s\n",getenv("PWD"));
	}	
	else if(count==2){
		if(strcmp(words[1],"-L")==0){
			char s[100];
			printf("%s\n",getenv("PWD"));
		}
		else if(strcmp(words[1],"-P")==0){
			char s[100];
			printf("%s\n",getcwd(s,100));
		}
		else{
			printf("Inavalid Command or option\n");
		}
	}
	else{
		printf("Invalid command or too many arguments\n");
	}
}

int main(){
	printf("Shell ------>\n");
while(1){
	char inp[10000];
	int i=0;
	char s[100];
	printf("Dir -> %s > ",getcwd(s,100));
	//scanf("%[^\n]s",inp);
	fgets(inp,sizeof(inp),stdin);
	if((strcmp(inp,"\r")==0) || (strcmp(inp,"\n")==0)){
		continue;
	}
	if(inp[strlen(inp)-1]=='\n'){
		inp[strlen(inp)-1]='\0';
	}
	char* t=strtok(inp," ");
	char* words[100];
	int count =0;
	while(t!=NULL){
		words[count++]=t;
		t=strtok(NULL," ");
	}	
	for(int k=0;k<count;k++){
		//printf("%s\n",words[k]);
	}
	if(strcmp(words[0],"cd")==0){
		char st[100];
		printf("Current directory is %s\n",getcwd(st,100));
		command_cd_func(words[1]);
	}
	else if(strcmp(words[0],"echo")==0){
		command_echo_func(words,count);
	}
	else if(strcmp(words[0],"rm")==0){
		if(strcmp(words[count-1],"&t")==0){
			char* fn=malloc(100);
			strcpy(fn,"./rm");
			thread_func(fn,words);
		}
		else{
			command_rm_func(words,count);
		}
	}
	else if(strcmp(words[0],"cat")==0){
		if(strcmp(words[count-1],"&t")==0){
			char* fn=malloc(100);
			strcpy(fn,"./cat");
			thread_func(fn,words);
		}
		else{
			command_cat_func(words,count);
		}
	}
	else if(strcmp(words[0],"date")==0){
		if(strcmp(words[count-1],"&t")==0 && strcmp(words[1],"-r")==0){
			char* fn=malloc(100);
			strcpy(fn,"./date2");
			thread_func(fn,words); 
		}
		else if(strcmp(words[count-1],"&t")==0){
			char* fn=malloc(100);
			strcpy(fn,"./date");
			thread_func(fn,words); 
		}
		else{
			command_date_func(words,count);
		}
	}
	else if(strcmp(words[0],"pwd")==0){
		command_pwd_func(words,count);
	}
	else if(strcmp(words[0],"ls")==0){
		if(strcmp(words[count-1],"&t")==0 && strcmp(words[1],"-1")==0){
			char* fn=malloc(100);
			strcpy(fn,"./ls2");
			thread_func(fn,words); 
		}
		else if(strcmp(words[count-1],"&t")==0 && strcmp(words[1],"-a")==0){
			char* fn=malloc(100);
			strcpy(fn,"./ls");
			thread_func(fn,words);
		} 
		else if(strcmp(words[count-1],"&t")==0){
			char* fn=malloc(100);
			strcpy(fn,"./ls1");
			thread_func(fn,words);
		}
		else{
			command_ls_func(words,count);
		}
	}
	else if(strcmp(words[0],"mkdir")==0){
		if(strcmp(words[count-1],"&t")==0 && count==4){
			char* fn=malloc(100);
			strcpy(fn,"./mkdir2");
			thread_func(fn,words); 
		}
		else if(strcmp(words[count-1],"&t")==0){
			char* fn=malloc(100);
			strcpy(fn,"./mkdir");
			thread_func(fn,words); 
		}
		else{
			command_mkdir_func(words,count);
		}
	}
	else if(strcmp(words[0],"exit")==0){
		break;
	}
	else{
		printf("Invalid Command\n");
	}
}
	return 0;
}
