#include <stdio.h>

int main(){
	int MI6 = 0, M4 = 0, M0 = 0;
	float i;
	printf("Digite uma nota: ");
	scanf("%f%*c", &i);
	while(i>=0){
		if(i>=6)
			MI6++;
		else 
			if(i>=4 && i<6)
				M4++;
			else
				M0++;
		printf("Digite uma nota: ");
		scanf("%f%*c", &i);			
	}
	printf("Maior ou igual a 6: %d\n", MI6);
	printf("Maior ou igual a 4: %d\n", M4);
	printf("Menor que 4: %d\n", M0);
}
