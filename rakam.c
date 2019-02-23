#include<stdio.h>

int main(int argc, char *argv[]){	
	int number = atoi(argv[0]);
	switch (number){
		case 0:
			printf("Cikti: %d >> sifir\n",number); break;
		case 1:
			printf("Cikti: %d >> bir\n",number); break;
		case 2:
			printf("Cikti: %d >> iki\n",number); break;
		case 3:
			printf("Cikti: %d >> uc\n",number); break;
		case 4:
			printf("Cikti: %d >> dort\n",number); break;
		case 5:
			printf("Cikti : %d >> bes\n",number); break;
		case 6:
			printf("Cikti: %d >> alti\n",number); break;
		case 7:
			printf("Cikti: %d >> yedi\n",number); break;
		case 8:
			printf("Cikti: %d >> sekiz\n",number); break;
		case 9:
			printf("Cikti: %d >> dokuz\n",number); break;
	}
	return 0;
}
