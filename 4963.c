#include <stdio.h>
int w = -1, h = -1;
//좌상, 위, 우상, 좌, 우, 좌하, 하, 우하
int dx[9] = {-1, 0, 1, -1, 1, -1, 0, 1}; 
int dy[9] = {-1, -1, -1, 0, 0, 1, 1, 1};
int visit[52][52] = {0, };
int map[52][52] = {0, };
void DFS(int y, int x) //같은 섬에서 이동하면서 방문 체크
{
	visit[y][x] = 1;
	for(int i = 0; i < 8; i++){
		
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx<w && ny<h && nx>=0 && ny>=0){
			if(visit[ny][nx] == 0 && map[ny][nx] == 1)
				DFS(ny, nx);
		}
	}
}
int main()
{
	int land = 0;
	while(1){
		scanf("%d %d", &w, &h);	
		if(w==0 && h==0)
			break;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(j == w-1){
					scanf("%d", &map[i][j]);
					getchar();
				}
				else scanf("%d ", &map[i][j]);
			}
		}
		
		for(int i = 0; i < h; i++){ // 섬 방문
			for(int j = 0; j < w; j++){
				if(visit[i][j] == 0 && map[i][j] == 1){
					DFS(i, j); 
					land++;
				}
			}
		}
		
		for(int i = 0; i < h; i++){ //방문 배열 초기화
			for(int j = 0; j < w; j++)
				visit[i][j] = 0;
		}
		printf("%d\n", land);
		land = 0;
	}
	return 0;
}