#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[25][25];					//����
bool visit[25][25] = { false };		//�湮����
vector<int> range;					//�� ������ ����
queue<pair<int, int>> q;			//���޵Ǵ� x,y��ǥ
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
	for (int i = 0; i < n; i++) {					//map�迭�� ���鼭 �������� �˻�
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == 1) {	//���� ������ �̾��� �κ��� �ƴϰ� 1�� �� ���ο� ������ ��������
				bfs(i, j);
			}
		}
	}
	sort(range.begin(), range.end());				//������ ������ �������� ����̿����Ƿ� ������ ���̸� �����س� �迭 ����
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
					range[tmp]++;					//tmp���� ���������μ� ���������� ���� �ش� ������ ���̸� ������Ŵ(�ѹ��� ã�� ������ ���̸� ����)
				}
			}
		}
	}
	tmp++;					//bfs�� �����ٴ� ���� �ϳ��� ������ �� Ž�� �Ϸ��ߴٴ� ���̹Ƿ� ������������ ���� tmp���� 1����
}