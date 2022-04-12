#include <stdio.h>
int main()
{
	int N=0;
	scanf("%d", &N);
	
	for(int i = 1; i<=2*N-1; i++){
		if(i<=N){
			for(int j = 0; j<i; j++) printf("*");
			for(int k = 0; k<2*N-2*i; k++) printf(" ");
			for(int j = 0; j<i; j++) printf("*");
			printf("\n");
		} else {
			for(int j = 2*N-i; j>0; j--) printf("*");
			for(int k = 0; k<2*(N-(2*N-i)); k++) printf(" ");
			for(int j = 2*N-i; j>0; j--) printf("*");
			printf("\n");
		}
	}	
}
