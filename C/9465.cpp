#include <stdio.h>
#define MAX(a,b) ((a)>(b) ? (a):(b))
int main()
{
	int n=0, test_case=0;
	scanf("%d", &test_case);
	getchar();

	while (test_case-- > 0) {
		int dp[100002][2] = {0,};
		int stiker[100001][2] = {0,};
		scanf("%d", &n);
		getchar();
		for(int j=0; j<=1; j++){
			for(int i=0; i<n; i++){
				scanf("%d", &stiker[i][j]);
			}
			getchar();
		}
		dp[0][0] = stiker[0][0];
		dp[0][1] = stiker[0][1];
		dp[1][0] = dp[0][1] + stiker[1][0];
		dp[1][1] = dp[0][0] + stiker[1][1];
		
		for(int i=2; i<n; i++){
			dp[i][0] = MAX(dp[i-1][1], dp[i-2][1]) + stiker[i][0];
			dp[i][1] = MAX(dp[i-1][0], dp[i-2][0]) + stiker[i][1];
		}
		printf("%lld\n", MAX(dp[n-1][0], dp[n-1][1]));
	}
	
}
