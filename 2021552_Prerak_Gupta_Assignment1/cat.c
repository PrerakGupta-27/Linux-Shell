#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(int argc,char* argv[]){
	if(argc==2){
		FILE* fp = fopen(argv[1],"r");
		if(!fp){
			printf("ERROR\n");
		}
		else{
			char ch;
			while((ch=fgetc(fp))!=EOF){
				printf("%c",ch);
			}
		}
		fclose(fp);
	}
	else if(argc==3){
		if(strcmp(argv[1],"-n")==0){
			FILE* fp =fopen(argv[2],"r");
			if(!fp){
				printf("ERROR\n");
			}
			else{
				char ch;
				int co=2;
				printf("1) ");
				while((ch=fgetc(fp))!=EOF){
					if(ch=='\n'){
						printf("%c%d) ",ch,co);
						co++;
					}
					else{
						printf("%c",ch);
					}
				}
				printf("\n");
			}
		}
		else if(strcmp(argv[1],"-s")==0){
			FILE* fp=fopen(argv[2],"r");
			if(!fp){
				printf("ERROR\n");		
			}
			else{
				char ch;
				bool flag=false;
				bool flag2=false;
				while((ch=fgetc(fp))!=EOF){
					if(ch=='\n' && flag && flag2){
						
					}
					else if(ch=='\n' && flag){
						printf("\n");
						flag2=true;
					}
					else if(ch=='\n'){
						printf("\n");
						flag = true;
					}
					else{
						printf("%c",ch);
						flag = false;
						flag2=false;
					}
				}
			}
		}
		else{
			printf("INVALID command");
		}
	}
	return 0;
}
