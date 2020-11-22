#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
int dp[1000002] = {0,};
int main()
{
	int n;
	dp[1]=0;
	scanf("%d", &n);
	for(int i=1; i<=n+1; i++){
		if(dp[i]==0){
			if(i%3==0&&i%2!=0){
				dp[i] = 1 + MIN(dp[i-1], dp[i/3]);
			}
			else if(i%6==0){
				dp[i] = 1 + MIN(dp[i/2], dp[i/3]);
			}
			else if(i%2==0&&i%3!=0){
				dp[i] = 1 + MIN(dp[i-1], dp[i/2]);
			}
			else{
				dp[i] = 1 + dp[i-1];
			}
		}
	}
	printf("%d ", dp[n]-1);	

} 
