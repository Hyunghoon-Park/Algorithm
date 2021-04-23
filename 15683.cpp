#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 100;
int map[8][8];
int cctv_size;
vector<pair<int,pair<int,int>>> v;      //카메라 종류, y좌표, x좌표
const int rotation[] = { 0, 4, 2, 4, 4, 1 };
 
void map_cpy(int desc[8][8], int src[8][8]){
    for(int i= 0; i < n; i++)
        for(int j = 0; j < m; j++)
            desc[i][j] = src[i][j];
}
// update 함수는 한 방향으로만 감시를 해 주는 함수.
void update(int dir, int y, int x){
    dir %= 4;    // dir값이 4보다 큰 값이 들어올 수 있으므로
    if(dir == 0){           //동쪽
        for(int i = x + 1; i < m; i++){
            if(map[y][i] == 6)
                break;
            map[y][i] = -1;
        }
    }
    else if(dir == 1){     //북쪽
        for(int i = y - 1; i >= 0; i--){
            if(map[i][x] == 6) 
                break;
            map[i][x] = -1;
        }
    }
    else if(dir == 2){     // 서쪽
        for(int i = x - 1; i >= 0; i--){
            if(map[y][i] == 6)
                break;
            map[y][i] = -1;
        }
    }
    else if(dir == 3){     // 남쪽
        for(int i = y + 1; i < n; i++){
            if(map[i][x] == 6) 
                break;
            map[i][x] = -1;
        }
    }
}
void dfs(int idx){
    if(idx == cctv_size){
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(map[i][j] == 0)
                    cnt++;
        ans = min(ans, cnt);
        return;
    }
    int backup[8][8];
    int type = v[idx].first;    //카메라 종류
 
    for(int dir = 0; dir < rotation[type]; ++dir){
        map_cpy(backup, map);       // map 백업
        if(type == 1){
            update(dir, v[idx].second.first, v[idx].second.second);
        }
        else if(type == 2){
            update(dir, v[idx].second.first, v[idx].second.second);
            update(dir + 2, v[idx].second.first, v[idx].second.second);
        }
        else if(type == 3){
            update(dir, v[idx].second.first, v[idx].second.second);
            update(dir + 1, v[idx].second.first, v[idx].second.second);
        }
        else if(type == 4){
            update(dir, v[idx].second.first, v[idx].second.second);
            update(dir + 1, v[idx].second.first, v[idx].second.second);
            update(dir + 2, v[idx].second.first, v[idx].second.second);
        }
        else if(type == 5){
            update(dir, v[idx].second.first, v[idx].second.second);
            update(dir + 1, v[idx].second.first, v[idx].second.second);
            update(dir + 2, v[idx].second.first, v[idx].second.second);
            update(dir + 3, v[idx].second.first, v[idx].second.second);
        }
        dfs(idx + 1);
        map_cpy(map, backup);       // map 복원 - 백트래킹
    }
}
 
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] != 0 && map[i][j] != 6){
                v.push_back({map[i][j],{i,j}});
                cctv_size++;
            }
        }
    }
    dfs(0);
    printf("%d", ans);
    return 0;
}
