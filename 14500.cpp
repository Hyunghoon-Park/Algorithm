#include <iostream>
#include <algorithm>

using namespace std;

int map[501][501] = {0,};
bool check[501][501] = {false,};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n, m, max_value = 0;

void specialshape(int y, int x){                //'ㅗ'모양은 따로 처리 해줘야 함
    if(y >= 1 && x >= 1 && x < m - 1)           //ㅗ (현재 좌표 ㅡ의 가운데)
        max_value = max(max_value, map[y][x - 1] + map[y][x] + map[y - 1][x] + map[y][x + 1]);
    if(y >= 1 && y < n - 1 && x < m - 1)       //ㅏ (현재 좌표 ㅣ의 가운데)
        max_value = max(max_value, map[y - 1][x] + map[y][x] + map[y][x + 1] + map[y + 1][x]);
    if(y < n - 1 && x >= 1 && x < m - 1)       //ㅜ (현재 좌표 ㅡ의 가운데)
        max_value = max(max_value, map[y][x - 1] + map[y][x] + map[y + 1][x] + map[y][x + 1]);
    if(y >= 1 && y < n - 1 && x >= 1)          //ㅓ (현재 좌표 ㅣ의 가운데)
        max_value = max(max_value, map[y - 1][x] + map[y][x] + map[y][x - 1] + map[y + 1][x]);
    
}

void bruteforce(int y, int x, int cnt, int value){
    if(cnt == 4){
        max_value = max(max_value, value);
        return;
    }
    for(int i = 0; i < 4; i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(0 <= yy && yy < n && 0 <= xx && xx <= m && check[yy][xx] == false){
            check[yy][xx] = true;
            bruteforce(yy,xx,cnt+1,value + map[yy][xx]);
            check[yy][xx] = false;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            check[i][j] = true;
            bruteforce(i,j,1,map[i][j]);
            specialshape(i,j);
            check[i][j] = false;
        }
    printf("%d", max_value);
    
}