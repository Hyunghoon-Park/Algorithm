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
 
    for(i = 0; i < n; i++){                           // 로우 확인
        int before_num = arr[i][0];
        isOver = 0;
        for(j = 1; j < n; j++){
            if(isOver) 
                break;
            if(before_num == arr[i][j])                     // 이전 숫자와 같으면 continue
                continue;
            else if(abs(before_num - arr[i][j]) >= 2){       // 이전 숫자와 2이상 차이나면 break;
                isOver = 1;
                break;
            }
            else if(before_num == arr[i][j] - 1){              //뒤에가 1만큼 더 크면 앞을 살핀다.
                isSlide = 1; 
                for(int t = 0; (t < l) && (isSlide); t++){
                    if((j - (t+1) < 0) || (isUsed[i][j - (t + 1)][0])){       // 인덱스를 벗어나거나 사용한 인덱스이면 종료 
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }
                    if(arr[i][j - (t + 1)] != before_num){              // 비교하는 숫자와 다르면 답이 아님 
                        isSlide = 0;
                        isOver = 1;
                        break;
                    }
                    isUsed[i][j - (t + 1)][0] = 1;
                }
            }
            else {                                              // 앞이 1만큼 더 크면 뒤를 살핀다. 
                isSlide = 1;

                for(int t = 0; (t < l) && (isSlide) ; t++){
                    if((j + t == n)|| (isUsed[i][j + t][0])){         // 인덱스를 벗어나거나 사용한 인덱스이면 종료 
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