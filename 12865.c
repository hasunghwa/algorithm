#include <stdio.h>
#define MAX(x, y) x>y?x:y
int main()
{
	int N = 0, K = 0;
	int dp[100002] = {0, };
	int w[102] = {0, };
	int v[102] = {0, };

	scanf("%d %d", &N, &K);
	
	for(int i = 1; i <= N; i++)
		scanf("%d %d", &w[i], &v[i]);

	for(int i = 1; i <= N; i++)
	{
		for(int j = K; j >= 1; j--)
		{	
			if(w[i] <= j)
				dp[j] = MAX(dp[j], dp[j-w[i]] + v[i]);	// dp[10] = dp[9] + v[1] w[i]가 1일때	
		}
	}
	
	printf("%d", dp[K]);
	return 0;
}