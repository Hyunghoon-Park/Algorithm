#include <iostream>
#include <algorithm>

using namespace std;

int n, k, low, high, result = -1;

int main(){
    scanf("%d %d", &n, &k);
    low = 1;
    high = k;
    int reslut = -1;
    while(low <= high){
        int cnt = 0;
        int mid = (low + high) / 2;
        for(int i = 1; i <= n; i++)
            cnt += min(mid / i, n);
        if(cnt < k)
            low = mid + 1;
        else{
            result = mid;
            high = mid - 1;
        }
    }
    printf("%d", result);
}