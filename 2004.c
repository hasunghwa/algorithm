/*
문제
nCm 의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n,m  (0<=m<=n<=200000000, n!=0 )이 들어온다.

출력
첫째 줄에 
nCm의 끝자리 0의 개수를 출력한다.
*/
#include <stdio.h>
#define MIN(a, b) a>b ? b : a
long long two_five_cnt[2] = {0, };
void cnt(long long x)
{
	two_five_cnt[0] = two_five_cnt[1] = 0;

	for(long long i = 2; i <= x ; i*=2)
	{
		two_five_cnt[0] += x / i;
	}
	
	for(long long i = 5; i <= x ; i*=5)
	{
		two_five_cnt[1] += x / i;
	}
}
int main()
{
	long long n = 0, m =0;
	long long ans[2] = {0, };
	scanf("%lld %lld", &n, &m);
	
	cnt(n);
	ans[0] = two_five_cnt[0];
	ans[1] = two_five_cnt[1];
	
	cnt(n-m);
	ans[0] -= two_five_cnt[0];
	ans[1] -= two_five_cnt[1];
	
	cnt(m);
	ans[0] -= two_five_cnt[0];
	ans[1] -= two_five_cnt[1];
	printf("%lld\n", MIN(ans[0], ans[1]));
}