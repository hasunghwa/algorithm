#include <stdio.h>
int dp[1001]={0,};
int sol(int n){
	if(n<=1){
		return 1;
	}
	if(dp[n]==0){
		dp[n] = sol(n-1) + sol(n-2);
	}
	return dp[n]%=10007;
}
int main()
{
	
	int n=0;
	scanf("%d", &n);
	
	printf("%d", sol(n));
}

