#include <iostream>
#include <queue>
using namespace std;

int map[101][101] = { 0 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, m;
queue<pair<int, int>> q;

void bfs(int x, int y);

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);
    printf("%d", map[n-1][m-1]);
	return 0;
}

void bfs(int x, int y) {
	q.push(pair<int, int>(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && map[xx][yy] == 1) {
                q.push(pair<int, int>(xx,yy));
                map[xx][yy] = map[x][y]+1;
			}
		}
	}
}