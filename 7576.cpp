#include <iostream>
#include <queue>
using namespace std;

int box[1000][1000] = { 0 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
queue<pair<int, int>> q;
int m, n, result = 1;

void bfs();

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &box[i][j]);
            if (box[i][j] == 1) {
                q.push(pair<int, int>(i, j));
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", result - 1);
    return 0;
}
void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && box[xx][yy] == 0) {
                box[xx][yy] = box[x][y] + 1;
                result = box[xx][yy];
                q.push(pair<int, int>(xx, yy));
            }
        }
    }
}