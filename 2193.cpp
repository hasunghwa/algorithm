#include <stdio.h>
int main()
{
	long long dp[91]={0,};
	int n=0;
	scanf("%d", &n);
	
	dp[0]=1;
	dp[1]=1;
		
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	printf("%lld", dp[n-1]);
}
