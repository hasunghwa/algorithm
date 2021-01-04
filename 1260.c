/*
문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
*/
#include <stdio.h>
int main()
{
	int arr[1002][1002] = {0, };
	int visited[1002] = {0, };
	
	int stack[1002] = {0, };
	int p = -1;	
	
	int queue[1002] = {0, };
	int front = -1, rear = -1;
	
	int n = 0, m = 0, v = 0, x = 0, y = 0;
	scanf("%d %d %d", &n, &m, &v);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		getchar();
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	int v2 = v;
	visited[v] = 1;
	printf("%d ", v);
	while(1){
		for(int i = 1; i <= n; i++){
			if(arr[v][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				stack[++p] = v;
				v = i;
				printf("%d ", v);
				break;
			}
			if(i == n){
				v = stack[p];
				stack[p--] = 0;
			}
		}
		
		if(p == -2) break;
	}
	for(int i = 1; i <= n; i++)
		visited[i] = 0;
	printf("\n");
	
	visited[v2] = 1;
	printf("%d ", v2);
	
	while(1){
		for(int i = 1; i <= n; i++){
			if( arr[v2][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				printf("%d ", i);
				queue[++rear] = i;		
			}
			if(i == n){
				v2 = queue[++front];
				queue[front] = 0;
			}
		}
		if(front>rear) break;
	}	
	
}