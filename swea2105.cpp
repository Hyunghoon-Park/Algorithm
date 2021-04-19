#include<iostream>
#include <algorithm>
using namespace std;

int n, result;
int map[20][20];
bool dessert[101];          
int dy[4] = {1,1,-1,-1};    //우하, 좌하, 좌상, 우상
int dx[4] = {1,-1,-1,1};

int count_dessert(){
    int tmp = 0;
    for(int i = 1; i < 101; i++)
        if(dessert[i] == true)
            tmp++;
    return tmp;
    
}

void dfs(int start_y, int start_x, int y, int x, int dir){      //시작좌표, 현재좌표, 방향
    if(dir == 4){
        if(start_y == y && start_x == x)            //끝난곳의 좌표와 시작 좌표가 같으면
            result = max(result, count_dessert());
        return;
    }
    int yy = y + dy[dir];
    int xx = x + dx[dir];
    if(0 <= yy && yy < n && 0 <= xx && xx < n && dessert[map[yy][xx]] == false){ //지도 안에있고 아직 안먹은 디저트 일때
        dessert[map[yy][xx]] = true;
        dfs(start_y, start_x, yy, xx, dir);
        dfs(start_y, start_x, yy, xx, dir+1);
        dessert[map[yy][xx]] = false;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        result = 0;
        fill(&map[0][0], &map[19][20], 0);
        fill(&dessert[0], &dessert[100], false);

        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &map[i][j]);
        for(int i = 0; i < n-2; i++)
            for(int j = 1; j < n-1; j++)
                dfs(i,j,i,j,0);
        printf("#%d ", test_case);
        if(result == 0)
            printf("-1\n");
        else
            printf("%d\n", result);
	}
	return 0;
}