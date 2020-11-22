#include <stdio.h>
int main()
{
	int dp[1001]={0,};
	int n=0, test_case=0;
	scanf("%d", &test_case);
	
	while(test_case!=0){
		scanf("%d", &n);
		dp[0]=0;
		dp[1]=1;
		dp[2]=2;
		dp[3]=4;
		
		for(int i=4; i<=n; i++){
			if(dp[i]==0){
				dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
			}
		}
		
		printf("%d\n", dp[n]);
		test_case--;
	}
}
