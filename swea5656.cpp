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
            tmp_arr[i][j] = arr[i][j];      //�迭����

    for(int i = 0; i < h; i++){
        if(arr[i][idx] != 0){           //����� ������
            q.push({i,idx});            //queue�� ����ְ� break;
            break;
        }
    }
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(arr[y][x] == 1){             //������ 1�̸� �׳� ����
            arr[y][x] = 0;
        }
        else{                           //������ 1�� �ƴϸ� ������ŭ
            for(int i = 0; i < 4; i++){
                int xx = x;
                int yy = y;
                for(int j = 0; j < arr[y][x] - 1; j++){     //������ ���ڸ�ŭ
                    xx += dx[i];
                    yy += dy[i];
                    if(0 <= xx && xx < w && 0 <= yy && yy < h && arr[yy][xx] != 0){    //�迭 �����ȿ��ְ� ����� ������
                        q.push({yy,xx});
                    }
                }
            }
            arr[y][x] = 0;
        }
        
    }
    for(int i = 0; i < w; i++){         //��ĭó��
        queue<int> space;
        for(int j = h-1; j >= 0; j--){  //�Ʒ�������
            if(arr[j][i] != 0){         //����� ������
                space.push(arr[j][i]);  //queue�� ����ְ�
                arr[j][i] = 0;          //0���� ����
            }
        }
        for(int j = h-1; space.size() > 0; j--){    //queue�� ũ�Ⱑ 0���� ũ�� �Ʒ��� ���� ä��
            arr[j][i] = space.front();
            space.pop();
        }
    }
    for(int i = 0; i < w; i++)
        dfs(i, cnt+1);
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            arr[i][j] = tmp_arr[i][j];  //�迭����
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