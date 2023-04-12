#include <stdio.h>

int main(){
	
	int A[10] = {8,3,1,7,10,12,77,100,33,54};
	int B[10] = {-2,-5,-14,5,6,12,17,20,66,16};
	int C[20] = {0};
	int i, a = 0, b = 0;
	
	for(i = 1; i <= 20; i++){
		if(i % 2 == 1){
			C[i-1] = A[a];
			a++;
		}
		else{
			C[i-1] = B[b];
			b++;
		}
	}
	for(i=0; i<20; i++)
		printf("%d, ", C[i]);
}
