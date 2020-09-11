#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[50][50] = { 0 };
bool check[50][50] = { false };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<int> v;
int t, m, n, k;

void dfs(int x, int y);

int main() {
	int x, y;
	scanf("%d", &t);
	v.resize(t);
	for (int z = 0; z < t; z++) {
		scanf("%d %d %d", &m, &n, &k);
		fill(&check[0][0], &check[0][0] + sizeof(check), false);
		fill(&map[0][0], &map[0][0] + 50*50, 0);
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == false && map[i][j] == 1) {
					dfs(i, j);
					v[z]++;
				}
			}
		}
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}

void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
			if (check[xx][yy] == false && map[xx][yy] == 1) {
				dfs(xx, yy);
			}
		}
	}
}