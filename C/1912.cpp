#include <stdio.h>
#define MAX(a,b) a<b ? b:a
int main()
{
	int n=0;
	int arr[100001]={0,};
	int dp[100001]={0,};
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
      scanf("%d", &arr[i]);   
	}
	
	dp[0]=arr[0];
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			
		}
	}
}
