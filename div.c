#include<stdio.h>

int main(int argc, char *argv[]){
	int n1 = atoi(argv[0]);
	int n2 = atoi(argv[1]);
	int div;
	if(n1>n2){
		div = n1 / n2;
	}
	else{ 
		div = n2 / n1;
	}
	printf("%d / %d = %d\n",n1,n2,div);
	return 0;
}
