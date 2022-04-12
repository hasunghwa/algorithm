#include <stdio.h>
int main()
{
	long long dp[102][11]={0,};
	int n=0;
	long long sum=0;
	scanf("%d", &n);
	
	for(int i=1; i<10; i++){
		dp[1][i]=1;
	}
	
	for(int i=2; i<=n; i++){
		for(int j=0; j<=10; j++){
			if(j==0){
				dp[i][j] = dp[i-1][j+1];
				dp[i][j] %= 1000000000;
			}
			else if(j>=1 && j<=8){
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
				dp[i][j] %= 1000000000;
			}
			else if(j==9){
				dp[i][j] = dp[i-1][j-1];
				dp[i][j] %= 1000000000;
			}
		}
	}
	for(int i=0; i<=10; i++){
		sum+=dp[n][i];
	}
	printf("%ld", sum%1000000000);
}
