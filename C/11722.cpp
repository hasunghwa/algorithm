#include <stdio.h>
#define MAX(a,b) (a>b ? a:b)
int main()
{
	int N=0, max=1;
	int arr[1001] = {0, };
	int dp[1001] = {0, };
	
	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	
	dp[0] = 1;
	
	for(int i=1; i<N; i++){
		dp[i] = 1;
		for(int j=i-1; j>=0; j--){
			if(arr[j] > arr[i] && dp[j] >= dp[i]){
				dp[i]= 1 + dp[j];
			}
		}
		max=MAX(max, dp[i]);
	}
	
	printf("%d", max);
}
