#include <stdio.h>
int main()
{
	int N = 0, div = 2;
	scanf("%d", &N);
	while(N != 1)
	{
		if(N % div == 0){
			printf("%d\n", div);
			N = (int)N/div;
			div = 1;
		}
		div ++;
		
	}
	return 0;
}