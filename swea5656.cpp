#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int t, n, w, h, min_value;
int arr[15][12] = {0,};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int count_wall(){
    int wall_num = w*h;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if(arr[i][j] == 0)
                wall_num--;
    return wall_num;
}
void dfs(int idx, int cnt){
    if(cnt == n){
        min_value = min(min_value, count_wall());
        return;
    }
    int tmp_arr[15][12];
    queue<pair<int,int>> q;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            tmp_arr[i][j] = arr[i][j];      //배열복사

    for(int i = 0; i < h; i++){
        if(arr[i][idx] != 0){           //블록을 만나면
            q.push({i,idx});            //queue에 집어넣고 break;
            break;
        }
    }
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(arr[y][x] == 1){             //벽돌이 1이면 그냥 폭파
            arr[y][x] = 0;
        }
        else{                           //벽돌이 1이 아니면 갯수만큼
            for(int i = 0; i < 4; i++){
                int xx = x;
                int yy = y;
                for(int j = 0; j < arr[y][x] - 1; j++){     //벽돌의 숫자만큼
                    xx += dx[i];
                    yy += dy[i];
                    if(0 <= xx && xx < w && 0 <= yy && yy < h && arr[yy][xx] != 0){    //배열 범위안에있고 블록이 있으면
                        q.push({yy,xx});
                    }
                }
            }
            arr[y][x] = 0;
        }
        
    }
    for(int i = 0; i < w; i++){         //빈칸처리
        queue<int> space;
        for(int j = h-1; j >= 0; j--){  //아래서부터
            if(arr[j][i] != 0){         //블록이 있으면
                space.push(arr[j][i]);  //queue에 집어넣고
                arr[j][i] = 0;          //0으로 만듬
            }
        }
        for(int j = h-1; space.size() > 0; j--){    //queue에 크기가 0보다 크면 아래서 부터 채움
            arr[j][i] = space.front();
            space.pop();
        }
    }
    for(int i = 0; i < w; i++)
        dfs(i, cnt+1);
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            arr[i][j] = tmp_arr[i][j];  //배열복귀
}

int main(int argc, char** argv)
{
	scanf("%d", &t);
    for(int z = 0; z < t; z++){
        min_value = 200;
        scanf("%d %d %d", &n, &w, &h);
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                scanf("%d", &arr[i][j]);
        for(int i = 0; i < w; i++)
            dfs(i, 0);
        printf("#%d %d\n", z+1, min_value);
    }
	return 0;
}