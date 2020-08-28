#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[25][25];					//지도
bool visit[25][25] = { false };		//방문여부
vector<int> range;					//각 단지의 넓이
queue<pair<int, int>> q;			//전달되는 x,y좌표
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, tmp;

void bfs(int x, int y);
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &tmp);
			map[i][j] = tmp;
		}
	}
	tmp = 0;
	for (int i = 0; i < n; i++) {					//map배열을 돌면서 시작점을 검사
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == 1) {	//기존 단지와 이어진 부분이 아니고 1인 즉 새로운 단지를 만났을때
				bfs(i, j);
			}
		}
	}
	sort(range.begin(), range.end());				//문제의 조건이 오름차순 출력이였으므로 단지의 넓이를 저장해논 배열 정렬
	printf("%d\n", range.size());
	for (int i = 0; i < range.size(); i++) {
		printf("%d\n", range[i]);
	}
	return 0;
}

void bfs(int x, int y) {
	range.push_back(1);
	q.push(pair<int, int>(x, y));
	visit[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < 25 && yy >= 0 && yy < 25) {
				if (!visit[xx][yy] && map[xx][yy] == 1) {
					q.push(pair<int, int>(xx, yy));
					visit[xx][yy] = true;
					range[tmp]++;					//tmp값은 전역변수로서 순차적으로 구한 해당 단지의 넓이를 증가시킴(한번에 찾는 단지의 넓이를 저장)
				}
			}
		}
	}
	tmp++;					//bfs가 종료됬다는 뜻은 하나의 단지를 다 탐색 완료했다는 뜻이므로 다음단지값을 위해 tmp값을 1증가
}