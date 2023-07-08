#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[]){
	if(argc==2){
		int status=remove(argv[1]);
		if(status==0){
			printf("Successfull\n");
		}
		else{
			printf("Unsuccessfull\n");
		}
	}
	else if(argc==3){
		if(strcmp(argv[1],"-i")==0){
			char c;
			printf("Press y to confirm ");
			scanf("%c",&c);
			if(c=='y'){
				int status=remove(argv[2]);
				if(status==0){
					printf("Deleted successfully\n");
				}
				else{
					printf("Error - unsuccessfull\n");
				}
			}
			else{
				printf("Aborted\n");
			}
		}
		else if(strcmp(argv[1],"-v")==0){
			int status=remove(argv[2]);
			if(status==0){
				printf("Deleting file %s\n",argv[2]);
				printf("Deleted successfully\n");
			}
			else{
				printf("Can't delete --> No such file or directory found - %s\n",argv[2]);
			}
		}
		else{
			printf("Error - Invalid Command\n");
		}
	}
	else{
		printf("InValid command\n");
	}
	return 0;
}
