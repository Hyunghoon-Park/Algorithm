#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[1001][1001];
bool visit[1001][1001][2];  //벽을 뚫었으면 [][][] = true 아니면 false  
int n, m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<int,int>> q;

int bfs();

int main(){
    int result;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    result = bfs();
    return 0;
}

int bfs(){

}