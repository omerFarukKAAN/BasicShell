#include<stdio.h>

int main(int argc, char *argv[]){
	int n1 = atoi(argv[0]);
	int n2 = atoi(argv[1]);
	int mul = n1*n2;
	printf("%d * %d = %d\n",n1,n2,mul);
	return 0;
}
