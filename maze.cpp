#include <stdio.h>
const int N = 8;
const int PATHWAY = 0;//아직 한 번도 가보지 못한 cell
const int WALL = 1;//벽이라고 정해진 cell
const int BLOCKED = 2;//visited이며 출구까지의 경로가 있지 않음이 밝혀진 cell
const int PATH = 3;//visited이며 아직 출구로 가는 경로가 될 가능성이 있는 cell
int map[N][N] = {
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 0, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 1, 0, 0}
};
bool findpath(int x, int y){
	if( x<0 || y<0 || x>=N || y >=N ){
		return false;
	}
	else if( map[x][y] != PATHWAY){
		return false;
	}
	else if( x == N-1 && y == N-1 ){
		map[x][y] = PATH;
		return true;
	}
	else{
		map[x][y] = PATH;
		if( findpath(x+1,y) || findpath(x,y-1) || findpath(x-1,y) || findpath(x,y+1) ){
			return true;
		}
		map[x][y] = BLOCKED;
		return false;
	}
}
int main(){
	findpath(0, 0);
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
