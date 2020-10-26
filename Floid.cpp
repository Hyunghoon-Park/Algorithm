#include <iostream>
#include <string.h>
#define MAX 100                 //���Ѵ�� ������ ū�� 100���� ��ü
using namespace std;
int P[5][5], D[5][5];
void floyd(int n, int W[][5], int D[][5], int P[][5]);
void path(int q, int r);
int main(){
    //int W[5][5] = {{0,1,MAX,1,5},{9,0,3,2,MAX},{MAX,MAX,0,4,MAX},{MAX,MAX,2,0,3},{3,MAX,MAX,MAX,0}};      //3. ������ �Էµ�����
    int W[5][5] = {{0,9,MAX,4,MAX},{MAX,0,10,6,7},{6,MAX,0,11,MAX},{MAX,6,MAX,0,1},{7,MAX,MAX,MAX,0}};      //4. ������ ���� �Էµ�����
    int D[5][5];
    floyd(5,W,D,P);
    path(0,4);                      //�迭�� 0������ �����߱� ������ ������ path(2,5)�� ����
    return 0;
}

void floyd(int n, int W[][5], int D[][5], int P[][5]){
    int i, j, k;
    for(i = 0; i < n; i++){         //P�迭 �ʱ�ȭ
        for(j = 0; j < n; j++){
            P[i][j] = 0;
        }
    }
    for(int i = 0; i < 5; i++){     //W�迭 D�� ����
        for(int j = 0; j < 5; j++){
                D[i][j] = W[i][j];
            }
    }
    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(D[i][k] + D[k][j] < D[i][j]){
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
        // for(int i = 0; i < 5; i++){              //������ �ڵ�
        //     for(int j = 0; j < 5; j++){
        //         printf("%d ",P[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        // for(int i = 0; i < 5; i++){
        //     for(int j = 0; j < 5; j++){
        //         printf("%d ",D[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("\n");
    }
    
}
void path(int q, int r){
    if(P[q][r] != 0){
        path(q,P[q][r]);
        printf(" V%d ",P[q][r]);    
        path(P[q][r], r);
    }
}