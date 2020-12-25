#include <iostream>

using namespace std;

int n;
int arr[500001];
int arr2[500001];

long long merge(int start, int end){
        if (start == end)
            return 0;
        int mid = (start + end) / 2;
        long long result = merge(start, mid) + merge(mid + 1, end);
        int i = start;
        int j = mid + 1;
        int idx = 0;
        while (i <= mid || j <= end){
            if (i <= mid && (j > end || arr[i] <= arr[j])){
                arr2[idx++] = arr[i++];
            }
            else{
                result += (mid - i + 1) * 1LL;
                arr2[idx++] = arr[j++];
            }
        }
        for (int k = start; k <= end; k++)
            arr[k] = arr2[k - start];
        return result;
}
int main(){
    long long result;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    result = merge(0, n-1);
    printf("%lld", result);
    return 0;
}