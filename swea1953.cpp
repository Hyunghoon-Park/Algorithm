#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r, c, l;
int map[51][51] = {0,};
bool visit[51][51];
int dy[4] = {-1,1,0,0};         //»óÇÏÁÂ¿ì
int dx[4] = {0,0,-1,1};

void bfs(int a, int b){
    queue<pair<int,pair<int,int>>> q;       //³¯ÀÚ, yÁÂÇ¥, xÁÂÇ¥
    visit[a][b] = true;
    q.push({1,{a,b}});
    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            int y = q.front().second.first;
            int x = q.front().second.second;
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(0 <= yy && yy < n && 0 <= xx && xx < m && visit[yy][xx] == false && q.front().first < l){   
                if(i == 0){                 //»ó
                    if(map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 4 || map[y][x] == 7){
                        if(map[yy][xx] == 1 || map[yy][xx] == 2 || map[yy][xx] == 5 || map[yy][xx] == 6){
                            q.push({q.front().first + 1,{yy,xx}});
                            visit[yy][xx] = true;
                        }
                    }
                }
                else if(i == 1){            //ÇÏ
                    if(map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 5 || map[y][x] == 6){
                        if(map[yy][xx] == 1 || map[yy][xx] == 2 || map[yy][xx] == 4 || map[yy][xx] == 7){
                            q.push({q.front().first + 1,{yy,xx}});
                            visit[yy][xx] = true;
                        }
                    }
                }
                else if(i == 2){            //ÁÂ
                    if(map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 6 || map[y][x] == 7){
                        if(map[yy][xx] == 1 || map[yy][xx] == 3 || map[yy][xx] == 4 || map[yy][xx] == 5){
                            q.push({q.front().first + 1,{yy,xx}});
                            visit[yy][xx] = true;
                        }
                    }
                }
                else if(i == 3){            //¿ì
                    if(map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 4 || map[y][x] == 5){
                        if(map[yy][xx] == 1 || map[yy][xx] == 3 || map[yy][xx] == 6 || map[yy][xx] == 7){
                            q.push({q.front().first + 1,{yy,xx}});
                            visit[yy][xx] = true;
                        }
                    }
                }
                
            }
        }
        q.pop();
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int result = 0;
        fill(&visit[0][0], &visit[50][51], false);
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &map[i][j]);         //input
        bfs(r, c);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(visit[i][j] == true)
                    result++;
        printf("#%d %d\n", test_case, result);
	}
	return 0;
}