#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, top, result;
int map[8][8];
bool visit[8][8];
int dir[][4] = {{-1,1,0,0}, {0,0,-1,1}};

void dfs(int y, int x, int cnt, bool use){                        //y좌표, x좌표, count갯수, 자를수 있는 기회
    result = max(result, cnt);
    for(int i = 0; i < 4; i++){
        int yy = y + dir[0][i];
        int xx = x + dir[1][i];
        if(0 <= yy && yy < n && 0 <= xx && xx < n && visit[yy][xx] == false){   //지도안에있고 아직 방문 안했다면
            if(map[y][x] <= map[yy][xx]){               //기존보다 같거나 클 경우
                if(use == true){                        //아직 자르는 기회를 사용 안했을 때
                    if((map[yy][xx] - map[y][x]) < k){  //이동하려는 곳과의 높이차이가 k보다 작을때
                        int tmp = map[yy][xx];        
                        visit[yy][xx] = true;
                        map[yy][xx] = map[y][x] - 1;    //1차이나는 상황이 가장 많은 경우의 수 보유
                        dfs(yy,xx,cnt+1,false);
                        visit[yy][xx] = false;
                        map[yy][xx] = tmp;
                    }
                }
            }
            else{                                       //기존보다 낮을경우
                visit[yy][xx] = true;
                dfs(yy,xx,cnt+1,use);
                visit[yy][xx] = false;
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        scanf("%d %d", &n, &k);
        fill(&visit[0][0], &visit[8][9], false);
        vector<pair<int,int>> v;
        result = 0;
        top = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &map[i][j]);
                top = max(top, map[i][j]);
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(map[i][j] == top)
                    v.push_back({i, j});
        for(int i = 0; i < v.size(); i++){
            visit[v[i].first][v[i].second] = true;
            dfs(v[i].first,v[i].second,1,true);
            
            visit[v[i].first][v[i].second] = false;
        }
        printf("#%d %d\n", test_case, result);
	}
	return 0;
}