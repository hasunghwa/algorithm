#include <stdio.h>
int factorialData[100] = {0,};
int factorial(int n)
{
	if(n <= 1) return 1;
	if(factorialData[n]==0)
		factorialData[n] = n * factorial(n-1);
	return factorialData[n];
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", factorial(n));
} 
