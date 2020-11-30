#include <stdio.h>
#define SWAP(a, b) { long long cup; cup = b; b = a; a = cup; }
long long gcd(long long a, long long b)
{
	if(a % b == 0) {return b;}
	else
		return gcd(b, a%b);
}
int main()
{
	long long A = 0, B = 0;
	scanf("%lld %lld", &A, &B);
	if(A<B) SWAP(A, B);

	long long i = gcd(A, B);
	while(i!=0){
		printf("1");
		i--;
	}
	printf("\n");
	return 0;
}
