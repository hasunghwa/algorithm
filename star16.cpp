#include <stdio.h>
int main()
{
	int N=0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<N+i; j++){
			if(i+j>N){
				if((i+j)%2!=0&&N%2==0)
					printf("*");
				else if((i+j)%2==0&&N%2==0)
					printf(" ");
				if((i+j)%2==0&&N%2!=0)
					printf("*");
				else if((i+j)%2!=0&&N%2!=0)
					printf(" ");
			}else{
				printf(" ");
			}
		
		}
		printf("\n");
	}
}
