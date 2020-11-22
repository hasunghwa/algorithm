#include <stdio.h>
int fiboData[100] = {0,};
int fibo(int n)
{
	if(n <= 2) return 1;
	if(fiboData[n]==0)
		fiboData[n] = fibo(n-1) + fibo(n-2);
	return fiboData[n];
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fibo(n));
} 
