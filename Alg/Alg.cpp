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
#define PATHWAY_COLOR 0 //white //���డ��
#define WALL_COLOR 1 //blue //��
#define BLOCKED_COLOR 2 //red //�ⱸ���� ��ΰ� �ƴѰ��
#define PATH_COLOR 3 //green //�ⱸ�� �� ���ɼ�

bool findMazePath(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N) {
		return false; //������ �Ұ����� �����ϰ�� �Ұ���
	}
	else if (maze[x][y] != PATHWAY_COLOR) {
		return false; //���డ���� �Ÿ��� �ƴҰ��(red.blue) �Ұ���
	}
	else if (x == N - 1 && y == N - 1) {
		maze[x][y] = PATHWAY_COLOR;//x,y�� ��ǥ�� �ⱸ�� ��ġ�ϴ���� true��ȯ
		return true;
	}

	else {
		maze[x][y] = PATH_COLOR;
		if (findMazePath(x - 1, y) || findMazePath(x, y + 1) || findMazePath(x + 1, y) || findMazePath(x, y - 1)) {
			return true;//��ǥ�� ����� Ž���Ͽ� ��θ� ã�´�.
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
	findMazePath(0, 0); //0,0ó������ ��ǥ�� �� Ž��
	printMaze();
}



