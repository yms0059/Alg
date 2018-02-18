#include<stdio.h>

#define N 8
#define MAZE_BOARD_HEIGHT 8
#define MAZE_BOARD_WIDTH 8
int i, j;

int maze[MAZE_BOARD_HEIGHT][MAZE_BOARD_WIDTH] = {
	{ 0,0,0,0,0,0,0,1 },
	{ 0,1,1,0,1,1,0,1 },
	{ 0,0,0,1,0,0,0,1 },
	{ 0,1,0,0,1,1,0,0 },
	{ 0,1,1,1,0,0,1,1 },
	{ 0,1,0,0,0,1,0,1 },
	{ 0,0,0,1,0,0,0,1 },
	{ 0,1,1,1,0,1,0,0 }
};
#define PATHWAY_COLOR 0 //white //통행가능
#define WALL_COLOR 1 //blue //벽
#define BLOCKED_COLOR 2 //red //출구까지 경로가 아닌경우
#define PATH_COLOR 3 //green //출구가 될 가능성

bool findMazePath(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N) {
		return false; //통행이 불가능한 범위일경우 불가능
	}
	else if (maze[x][y] != PATHWAY_COLOR) {
		return false; //통행가능한 거리가 아닐경우(red.blue) 불가능
	}
	else if (x == N - 1 && y == N - 1) {
		maze[x][y] = PATHWAY_COLOR;//x,y의 좌표가 출구와 일치하느경우 true반환
		return true;
	}

	else {
		maze[x][y] = PATH_COLOR;
		if (findMazePath(x - 1, y) || findMazePath(x, y + 1) || findMazePath(x + 1, y) || findMazePath(x, y - 1)) {
			return true;//좌표의 사방을 탐색하여 경로를 찾는다.
		}
		maze[x][y] = BLOCKED_COLOR;
		return false;
	}
}

void printMaze() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d",maze[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}


int main() {
	printMaze();
	findMazePath(0, 0); //0,0처음부터 좌표를 찍어서 탐색
	printMaze();
}



