#include <iostream>
#include <algorithm>
using namespace std;
int n, m, min_result = 64;
char board[50][50];

void count_square(int y, int x){
    int tmp = 0;
    for(int i = y; i < y+8; i++){
        for(int j = x; j < x+8; j++){
            if(((i+j) % 2) == 0 && board[i][j] != 'W')
                tmp++;
            if(((i+j) % 2) == 1 && board[i][j] != 'B')
                tmp++;
        }
    }
    min_result = min(min_result, tmp);
    tmp = 0;
    for(int i = y; i < y+8; i++){
        for(int j = x; j < x+8; j++){
            if(((i+j) % 2) == 0 && board[i][j] != 'B')
                tmp++;
            if(((i+j) % 2) == 1 && board[i][j] != 'W')
                tmp++;
        }
    }
    min_result = min(min_result, tmp);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    for(int i = 0; i <= n - 8; i++)
        for(int j = 0; j <= m - 8; j++)
            count_square(i,j);
    printf("%d", min_result);
}