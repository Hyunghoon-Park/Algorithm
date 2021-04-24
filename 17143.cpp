#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, m, sum = 0;
vector<pair<int, pair<int, int>>> shark[101][101];              //크기, 속력, 방향
queue<pair<pair<int,int>,pair<int,pair<int,int>>>> q;           //y, x, 크기, 속력, 방향

int dy[] = {-1,1,0,0};                  //상 하 우 좌
int dx[] = {0,0,1,-1};

void catch_shark(int x){
    for(int y = 1; y <= R; y++)
        if(shark[y][x].size()){
            sum += shark[y][x].front().first;
            shark[y][x].pop_back();
            break;
        }
}

void move_shark(){
    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            if(shark[i][j].size()){
                q.push({{i,j},{shark[i][j][0]}});
                shark[i][j].clear();
            }
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int big = q.front().second.first;
        int speed = q.front().second.second.first;
        int dir = q.front().second.second.second;
        q.pop();
        int yy = y;
        int xx = x;
        for(int i = 0; i < speed; i++){         //상어 이동
            if(!(1 <= yy + dy[dir] && yy + dy[dir] <= R && 1 <= xx + dx[dir] && xx + dx[dir] <= C)){   //다음칸이 칸 밖으로 나가면
                if(dir == 0)
                    dir = 1;
                else if(dir == 1)
                    dir = 0;
                else if(dir == 2)
                    dir = 3;
                else if(dir == 3)
                    dir = 2;                    
            }
            yy += dy[dir];
            xx += dx[dir];
        }
        if(shark[yy][xx].size() == 0)                       //해당 칸에 아무상어도 없으면
            shark[yy][xx].push_back({big,{speed,dir}});     //바로 넣음
        else{                                               //해당 칸에 상어가 이미 있으면
            int tmp_big = shark[yy][xx].front().first;      //기존 상어의 무게
            if(tmp_big < big){                              //새로 들어온 상어의 무게가 더 크면
                shark[yy][xx].clear();                      //기존 상어 제거
                shark[yy][xx].push_back({big,{speed,dir}}); //새로 들어온 상어 넣음
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &R, &C, &m);
    int r, c, s, d, z;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        if(d == 1 || d == 2)                            //위, 아래로 움직이는 상어라면
            s = s % ((R-1)*2);
        if(d == 3 || d == 4)                            //좌, 우로 움직이는 상어라면
            s = s % ((C-1)*2);
        shark[r][c].push_back({ z, {s, d - 1} });
    }
    for(int i = 1; i <= C; i++){
        catch_shark(i);
        move_shark();
    }
    printf("%d", sum);
}