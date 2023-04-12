#include <stdio.h>

int main(){
	
	int VetorInicial[8] = {8,-2,3,1,-5,7,-14,10}, VetorP[8] = {0}, VetorN[8] = {0};
	int P = 0, N = 0;
	int i;
	
	for(i=0; i<8; i++){
		if(VetorInicial[i] >= 0){
			VetorP[P] = VetorInicial[i];
			P++;
		} else {
			VetorN[N] = VetorInicial[i];
			N++;
		}
	}
	for(i=0; i<P;i++)
		printf("%d, ", VetorP[i]);
	printf("\n");
	for(i=0; i<N;i++)
		printf("%d, ", VetorN[i]);
}
