#include<iostream>
#include <algorithm>

using namespace std;

int d, w, k, min_value;
int protect[13][20];

bool check(int x){                      //���������� check�� true, �ƴϸ� false
    bool result = false;
    int before = protect[0][x];
    int cnt = 1;
    for(int y = 1; y < d; y++){
        if(protect[y][x] == before)
            cnt++;
        else{
            cnt = 1;
            before = protect[y][x];
        }
        if(cnt == k){
            result = true;
            break;
        }
    }
    return result;
}

void dfs(int y, int cnt){
    if(cnt == k)
        return;
    int tmp = 0;
    //k�� ������ �ϼ��Ǿ��� ��
    for(int i = 0; i < w; i++){
        if(check(i))       
            tmp++;
        else
            break;
    }
    if(tmp == w){                           //w���� �� ��� check ����ߴٸ�
        min_value = min(min_value, cnt);
        return;
    }
    // ������ ���� �ȵǾ��� ��
    int tmp_protect[20];
    for(int i = y; i < d; i++){
        if(min_value > cnt+1){
            for(int j = 0; j < w; j++)
                tmp_protect[j] = protect[i][j];
            for(int j = 0; j < w; j++)
                protect[i][j] = 1;          //�ش� �� ��� 1�� �ٲ�
            dfs(i+1, cnt+1);
            for(int j = 0; j < w; j++)
                protect[i][j] = tmp_protect[j];
        }
        if(min_value > cnt+1){
            for(int j = 0; j < w; j++)
                tmp_protect[j] = protect[i][j];
            for(int j = 0; j < w; j++)
                protect[i][j] = 0;          //�ش� �� ��� 0�� �ٲ�
            dfs(i+1, cnt+1);
            for(int j = 0; j < w; j++)
                protect[i][j] = tmp_protect[j];
        }
    }
}

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        scanf("%d %d %d", &d, &w, &k);
        min_value = k;
        for(int i = 0; i < d; i++)
            for(int j = 0; j < w; j++)
                scanf("%d", &protect[i][j]);
        dfs(0,0);
        printf("#%d %d\n", test_case, min_value);
	}
	return 0;
}