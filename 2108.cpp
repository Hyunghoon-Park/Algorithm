#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, input;
double sum = 0;
vector<int> arr;
int arr2[8001] = {0,};
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        arr.push_back(input);
        sum += input;
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++)
        arr2[arr[i]+4000]++;
    int max_value = *max_element(arr2, arr2+8001);
    int k, count = 0;
    for(int i = 0; i < 8001; i++){
        if(arr2[i] == max_value){
            k = i;
            count++;
        }
        if(count == 2)
            break;
    }
    printf("%.0f\n", sum / n);
    printf("%d\n", arr[n/2]);
    if(arr.size() == 1)
        printf("%d\n", input);
    else
        printf("%d\n", k - 4000);
    printf("%d", arr[arr.size()-1] - arr[0]);
}