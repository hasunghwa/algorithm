#include <stdio.h>
#include <stdbool.h>
#define SWAP(A, B) { int cup = B; B = A; A = cup; }
int arr[26][26] = {0, };
bool visit[26][26] = {false, };
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int N = 0, house = 0, count = 0;
void DFS(int x, int y)
{
	visit[x][y] = 1;
	house++;
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		if(nx>=0 && nx<N && ny>=0 && ny<N){
			if(visit[nx][ny]==0 && arr[nx][ny]==1)
				DFS(nx, ny);
		}
	}
}
int main()
{
	char line[26];
	int sort[313];
	scanf("%d", &N);
	getchar();
	
	for(int i=0; i<N; i++){ // 입력받은 문자열(line) 숫자로 변환
		scanf("%s", line);
		for(int j=0; j<N; j++){
			arr[i][j] = line[j] -'0';
		}
		getchar();
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i][j] == 1 && visit[i][j] == 0){
				DFS(i, j);
				sort[count++] = house;
				house = 0;
			}
		}
	}
	
	
	for(int i=0; i<count-1; i++){
		for(int j=i+1; j<count; j++){
			if(sort[i] > sort[j])
				SWAP(sort[i], sort[j]);
		}
	}
	printf("%d\n", count);
	for(int i=0; i<count; i++)
		printf("%d\n", sort[i]);
	return 0;
}