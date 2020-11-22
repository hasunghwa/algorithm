#include <stdio.h>
int main()
{
	long long dp[1002][11]={0,};
	int n=0;
	long long sum=0;
	scanf("%d", &n);
	
	for(int i=0; i<10; i++){
		dp[1][i]=1;
	}
	
	for(int i=2; i<=n; i++){
		for(int j=0; j<=10; j++){
			for(int k=j; k<=10; k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	for(int i=0; i<10; i++){
		sum+=dp[n][i];
	}
	printf("%ld", sum%10007);
}
