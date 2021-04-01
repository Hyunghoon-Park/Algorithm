#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int n, l;
int LNum = 0; 
int i, j; int isSlide, isOver;
int arr[100][100];          
int isUsed[100][100][2];
int answer = 0; 
 
int main() {
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]); 
 
    for(i = 0; i < n; i++){                           // �ο� Ȯ��
        int before_num = arr[i][0];
        isOver = 0;
        for(j = 1; j < n; j++){
            if(isOver) 
                break;
            if(before_num == arr[i][j])                     // ���� ���ڿ� ������ continue
                continue;
            else if(abs(before_num - arr[i][j]) >= 2){       // ���� ���ڿ� 2�̻� ���̳��� break;
                isOver = 1;
                break;
            }
            else if(before_num == arr[i][j] - 1){              //�ڿ��� 1��ŭ �� ũ�� ���� ���ɴ�.
                isSlide = 1; 
                for(int t = 0; (t < l) && (isSlide); t++){
                    if((j - (t+1) < 0) || (isUsed[i][j - (t + 1)][0])){       // �ε����� ����ų� ����� �ε����̸� ���� 
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }
                    if(arr[i][j - (t + 1)] != before_num){              // ���ϴ� ���ڿ� �ٸ��� ���� �ƴ� 
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }
                    isUsed[i][j - (t + 1)][0] = 1;
                }
            }
            else {                                              // ���� 1��ŭ �� ũ�� �ڸ� ���ɴ�. 
                isSlide = 1;

                for(int t = 0; (t < l) && (isSlide) ; t++){
                    if((j + t == n)|| (isUsed[i][j + t][0])){         // �ε����� ����ų� ����� �ε����̸� ���� 
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }  
                    if(arr[i][j + t] != before_num-1){ 
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }
                    isUsed[i][j + t][0] = 1 ;
                }
                if(isSlide && !isOver ) 
                    j += (l-1);
            }
            if(isSlide)
                before_num = arr[i][j]; 
 
        }
        if(!isOver)
            answer++;
    }
    for (j = 0; j < n; j++) {
        int before_num = arr[0][j];
        isOver = 0;
        for (i = 1; i < n; i++) {
            if(isOver) 
                break;
            if(before_num == arr[i][j]) 
                continue;
            else if(abs(before_num - arr[i][j]) >= 2){
                isOver = 1;
                break;
            }
            else if(before_num == arr[i][j] - 1){
                isSlide = 1; 
                for(int t = 0; (t < l) && (isSlide); t++){
                    if((i - (t + 1) < 0) || (isUsed[i - (t + 1)][j][1])){
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }
                    if(arr[i - (t + 1)][j] != before_num){
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }
                    isUsed[i - (t + 1)][j][1] = 1;
                }
            }
            else{
                isSlide = 1;
                for(int t = 0; (t < l) && (isSlide); t++){
                    if((i + t == n) || (isUsed[i + t][j][1])){
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }
                    if(arr[i + t][j] != before_num - 1){
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }
                    isUsed[i + t][j][1] = 1;
                }
                if(isSlide && !isOver)
                    i += (l - 1);
            }
 
            if(isSlide)
                before_num = arr[i][j];
        }
        if(!isOver)
            answer++;
    }
    printf("%d", answer);
}