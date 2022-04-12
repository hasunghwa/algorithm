#include <stdio.h>
#define MAX(a,b) (a>b ? a:b)
int main()
{
	int N=0, max_r=0, max_l=0;
	int arr[1001]={0, };
	int dp[2][1001]={0, };
	
	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);	
	}
	
	dp[0][0]=dp[1][0]=1;
	for(int i=1; i<N; i++){
		dp[0][i]=dp[1][i]=1;
		for(int j=i-1; j>=0; j--){
			if(arr[j]<arr[i] && dp[0][i] <= dp[0][j]){
				dp[0][i]=1+dp[0][j];
			} else if(arr[i]<arr[j] && dp[0][j] <= dp[0][i]){
				dp[1][j]=1+dp[1][i];
			}
		}
		max_r=MAX(max_r, dp[0][i]);
		max_l=MAX(max_l, dp[1][N-i]);
	}
	
	for(int i=0; i<N; i++){
		printf("%d ", dp[0][i]);
	}
	printf("\n");
		for(int i=0; i<N; i++){
		printf("%d ", dp[1][i]);
	}
}
