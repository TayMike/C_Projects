#include <stdio.h>

int main(){
	
	char lixo[2];
	
	for(int i=1; i<=10; i++){
		printf("\nTabuada do %d:\n", i);
		for(int n=1; n<=10; n++){
			printf("%d x %d = %d\n", i, n, i*n);
		}
		printf("\nAperte <enter> para continuar...");
		gets(lixo);
	}
}
