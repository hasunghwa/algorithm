/*
첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다. 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1,000,000을 넘지 않는다.
*/
#include <stdio.h>
#define SWAP(A, B) { int cup; cup = A; A = B; B = cup; }  
int gcd(int a, int b)
{
	if(a % b == 0)
		return b;
	else
		return gcd(b, a%b);
}
int main()
{
	int t = 0, n = 0;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		int arr[101] = {0, };
		long long ans = 0;
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n; j++){
				int a = arr[i], b = arr[j];
				if(a < b) SWAP(a, b);
				ans += gcd(a, b);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}