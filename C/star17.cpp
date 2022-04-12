#include <stdio.h>
int main()
{
	int N=0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<N+i; j++){
			if(i+j>N){
				if(N==i){
					printf("*");
					continue;
				}
				if((i+j==N+1||j==N+i-1)&&N!=i){
					printf("*");
				}
				else
					printf(" ");
			}else{
				printf(" ");
			}
		
		}
		printf("\n");
	}
}
