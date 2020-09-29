#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int n, m, result = 0;
int map[9][9], map2[9][9];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;

void count_zero(int arr[9][9]);
void make_wall(int n);
void bfs();
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                make_wall(1);
                map[i][j] = 0;
            }
        }
    }
    printf("%d", result);
    return 0;
}

void count_zero(int arr[9][9]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0)
                count++;
        }
    }
    result = max(result, count);
}
void make_wall(int cnt) {
    if (cnt == 3) {
        memcpy(map2, map, sizeof(map));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 2) {
                    q.push(pair<int, int>(i, j));
                }
            }
        }
        bfs();
        count_zero(map2);
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;                    
                    make_wall(cnt + 1);
                    map[i][j] = 0;
                }
            }
        }
    }
}
void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                if (map2[xx][yy] == 0) {
                    q.push(pair<int, int>(xx, yy));
                    map2[xx][yy] = 2;
                }
            }
        }
    }
}