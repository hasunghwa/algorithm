#include <stdio.h>
#define MAX(a,b) (a>b ? a:b)
int main()
{
	int n=0, max=0, maxdp=-1;
	int arr[1001]={0, };
	int dp[1001]={0, };
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	dp[0]=arr[0];
	max=arr[0];
	for(int i=1; i<n; i++){
		dp[i]=arr[i];
		maxdp=0;
		for(int j=i-1; j>=0; j--){
			if(arr[j]<arr[i]){
				maxdp=MAX(maxdp, dp[j]);
			}
		}
		dp[i]+=maxdp;
		max=MAX(max, dp[i]);
	}
	printf("%d", max);
}
