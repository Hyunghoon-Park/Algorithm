#include <iostream>
#include <queue>
using namespace std;

void bfs(int y, int x);
int n;
int answer = 0;
int map[11][11];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,int>> q;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &map[i][j]);
		}
	}
	bfs(0,0);
	printf("%d", map[n-1][n-1]);
	return 0;
}

void bfs(int y, int x){
	q.push(pair<int,int>(y,x));
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 && xx < n && yy >= 0 && y < n && map[yy][xx] == 1){
				q.push(pair<int,int>(yy,xx));
				map[yy][xx] = map[y][x] + 1;
			}
		}
	}
}