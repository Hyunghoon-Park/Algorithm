#include <iostream>
#include <algorithm>
using namespace std;

int n;
int m;
int arr[101];
int main(){
    int value = 100001;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i != j && j != k && k != i && (arr[i] + arr[j] + arr[k]) <= m){
                    value = min(m - (arr[i] + arr[j] + arr[k]), value);
                }
            }
        }
    }
    printf("%d", m - value);
    return 0;
}