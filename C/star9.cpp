#include <stdio.h>
int main()
{
	int N=0;
	scanf("%d", &N);
	
	for(int i = 1; i<=2*N-1; i++){
		if(i<=N){
			for(int j = 1; j<=i-1; j++){
				printf(" ");
			}
			for(int k = 1; k<=2*N-((i-1)*2+1); k++){
				printf("*");
			}
		}
		if(i>N){
			for(int j = 2*N-(1+i); j > 0; j--){
				printf(" ");
			}
			for(int k = i-(2*N-1-i); k > 0; k--){
				printf("*");
			}
		}
		printf("\n");
	}	
}


