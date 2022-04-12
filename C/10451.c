#include <stdio.h>
int visit[1002] = {0, };
int N = 0;
void DFS(int *arr, int n)
{
	if(visit[n] == 1)
		return;
	
	visit[n] = 1;
	DFS(arr, arr[n]);
}
int main()
{
	int T = 0, n = 0, ans;
	int arr[1002] = {0, };
	
	scanf("%d", &T);
	getchar();	
	while(T-- != 0){
		ans = 0;
		scanf("%d", &N);
		for(int i = 1; i<=N; i++){
			if(i == N) scanf("%d", &n);
			else scanf("%d ", &n);
			arr[i] = n;
		}	

		for(int i = 1; i<=N; i++){
			if(visit[i] == 0){
				DFS(arr, i);
				ans++;
			}
		}
		
		for(int i = 1; i<=N; i++)
			visit[i] = 0;
		printf("%d\n", ans);
	}
}