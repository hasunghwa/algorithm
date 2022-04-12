/*
문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.
*/
#include <stdio.h>
int arr[1002][1002] = {0, };
int visited[1002] = {0, };
void dfs(int v, int N)
{
	int stack[1002] = {0, };
	int p = -1;
	
	visited[v] = 1;
	//printf("%d ", v);
	while(1){
		for(int i = 1; i <= N; i++){
			if(arr[v][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				stack[++p] = v;
				//printf("%d ", i);
				v = i;
				break;
			}
			if(i == N){	
				if(p == -1) { p--; break; } 
				v = stack[p];
				stack[p--] = 0;
			}
		}
		if(p == -2) break;
	}	
}
int solution(int N)
{
	int cnt = 0;
	
    for(int i = 1; i <= N; i++){
		if(visited[i] == 0){
			cnt++;
			dfs(i, N);
		}
	}    
	return cnt;
}
int main()
{
	int N = 0, M = 0, u = 0, v = 0;
	
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d %d", &u, &v);
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	printf("%d ", solution(N));
}