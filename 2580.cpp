#include <iostream>

using namespace std;

int sudoku[10][10]; //������ ��
int col[10][10];    //��
int row[10][10];    //��
int box[10][10];    //�׸�ڽ�
int main(){
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            scanf("%d", sudoku[i][j]);
        }
    }
    return 0;
}