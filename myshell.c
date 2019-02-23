#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *commands[6] = {"rakam", "div", "mul", "cat", "clear", "exit"};

static void runCommand(char *parameters[]){
	char *arguments[3];
	for(int i = 0; i<3; i++){
		arguments[i] = (char*)malloc(5 * sizeof(char));
	}
	int i;
        if(strcmp(parameters[0], commands[0]) == 0){
       		strcpy(arguments[0],parameters[1]);
		arguments[1] = NULL;	
		int fv = fork();
        	if(fv==0){
			i = execv("rakam", arguments);
		}
		wait(5);
	}
	else if(strcmp(parameters[0], commands[1]) == 0){
       		strcpy(arguments[0],parameters[1]);
		strcpy(arguments[1],parameters[2]);
		arguments[2] = NULL;
		int fv = fork();
		if(fv==0){
			i = execv("div", arguments);
		}
		wait(5);
	}
	else if(strcmp(parameters[0], commands[2]) == 0){
        	strcpy(arguments[0],parameters[1]);
		strcpy(arguments[1],parameters[2]);
		arguments[2] = NULL;
		int fv = fork();
		if(fv==0){
			i = execv("mul", arguments);
		}
		wait(5);
	}
	else if(strcmp(parameters[0], commands[3]) == 0){
       		printf("cat: %s\n", parameters[1]);
	}
	else if(strcmp(parameters[0], commands[4]) == 0){
        	system("clear");
	}
}
static int wrongCommand(char *enter){
    int size = sizeof(commands) / sizeof(commands[0]);
    int trueCommand = 0;
    for (int i = 0; i < size; i++){
        if(strcmp(enter, commands[i]) == 0){
            trueCommand = 1;
        }
    }
    return trueCommand;
}
int main(void){
    char command[25];
    do {
        printf("myShell>> ");
        gets(command);
        char *parameters[7];
	for(int i=0; i<7; i++){
		parameters[i] = (char*)malloc(5 * sizeof(char));
	}
	char *pch;
	int no = 0;
	pch = strtok(command, " ");
	while(pch != NULL){
		strcpy(parameters[no], pch);
		no++;
		pch = strtok(NULL, " ");
	}
	if(wrongCommand(parameters[0]) == 0){
		puts("Yanlis bir komut girdiniz !");
	}else{
		if(strcmp(parameters[3],"&") == 0){
			if(wrongCommand(parameters[4]) == 0){
				puts("Yanlis bir komut girdiniz !");
			}
			char *firstParameters[4];
			char *secondParameters[4];
			for(int i = 0; i<4; i++){
				firstParameters[i] = (char*)malloc(5 * sizeof(char));
				secondParameters[i] = (char*)malloc(5 * sizeof(char));
			}
			strcpy(firstParameters[0], parameters[0]);
			strcpy(firstParameters[1], parameters[1]);
			strcpy(firstParameters[2], parameters[2]);
			strcpy(secondParameters[0], parameters[4]);
			strcpy(secondParameters[1], parameters[5]);
			strcpy(secondParameters[2], parameters[6]);
			runCommand(firstParameters);
			runCommand(secondParameters);
		}else if(strcmp(parameters[2],"&") == 0){
			char *firstParameters[4];
			char *secondParameters[4];
			for(int i = 0; i<4; i++){
				firstParameters[i] = (char*)malloc(5 * sizeof(char));
				secondParameters[i] = (char*)malloc(5 * sizeof(char));
			}
			strcpy(firstParameters[0], parameters[0]);
			strcpy(firstParameters[1], parameters[1]);
			strcpy(secondParameters[0], parameters[3]);
			strcpy(secondParameters[1], parameters[4]);
			strcpy(secondParameters[2], parameters[5]);
			runCommand(firstParameters);
			runCommand(secondParameters);
		}else{
			runCommand(parameters);
		}
	}
    }
    while (strcmp(command, "exit") != 0);
    exit(0);
}
