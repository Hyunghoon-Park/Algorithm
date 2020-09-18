#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001] = {0};

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(i + 1 <= n){
            if(dp[i+1] == 0){
                dp[i+1] = dp[i] + 1;
            }
            else{
                dp[i+1] = min(dp[i]+1, dp[i+1]);
            } 
        }
        if(i * 2 <= n){
            if(dp[i*2] == 0){
                dp[i*2] = dp[i] + 1;
            }
            else{
                dp[i*2] = min(dp[i]+1, dp[i*2]);
            }
        }
        if(i * 3 <= n){
            if(dp[i*3] == 0){
                dp[i*3] = dp[i] + 1;
            }
            else{
                dp[i*3] = min(dp[i]+1, dp[i*3]);
            }
        }
    }
    printf("%d",dp[n]);
    return 0;
}