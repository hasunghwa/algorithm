#include <stdio.h>
#define MAX(a,b) (a>b ? a:b) 
int main()
{
	int n=0, max=1;
	int arr[1001]={0, };
	int dp[1001]={0, };
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	dp[0]=1;
	for(int i=1; i<n; i++){
		dp[i]=1;
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i] && dp[i] <= dp[j]){
				dp[i]=dp[j]+arr[j];
			}
		}
		max=MAX(max, dp[i]);
	}
	printf("%d", max);
}
