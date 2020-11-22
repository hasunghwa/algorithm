#include <stdio.h>
int main()
{
	int N=0;
	scanf("%d", &N);
	
	for(int i = 1; i<=2*N-1; i++){
		for(int j = N; j>0; j--){
			if(i<=N){
				if(i>=j) printf("*");
				else printf(" ");
			}
			else{
				if(i-N<(N-j)+1) printf("*");
				else printf(" ");
			}
		}
		printf("\n");
	}	
}







