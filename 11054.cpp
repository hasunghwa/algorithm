#include <stdio.h>
#define MAX(a,b) (a>b ? a:b)
int main()
{
   int N=0, max=0;
   int arr[1001]={0, };
   int dp[2][1001]={0, };
   
   scanf("%d", &N);
   
   for(int i=0; i<N; i++){
      scanf("%d", &arr[i]);   
   }
   
   dp[0][0]=dp[1][N-1]=1;
   for(int i=1; i<N; i++){
      dp[0][i]=1;
      dp[1][N-i-1]=1;
      for(int j=i-1; j>=0; j--){
	  	if(arr[j]<arr[i] && dp[0][i] <= dp[0][j]){        
        	dp[0][i]=1+dp[0][j];
        }
        if(arr[N-i-1]>arr[N-j-1] && dp[1][N-i-1] <= dp[1][N-j-1] ){
            dp[1][N-i-1]=1+dp[1][N-j-1];        
        }
      }
   
   }
  for(int i=0; i<N; i++){
       max = MAX(dp[0][i]+dp[1][i], max);
   }

   printf("%d", max-1);
}

