#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, k, c, input, result = 0, max_value = 0;;
vector<int> v;
int arr[3001] = {0,};

int main(){
    scanf("%d %d %d %d", &n, &d, &k, &c);
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        v.push_back(input);
    }
    arr[c]++;
    result++;
    for(int i = 0; i < k; i++){                     //ó������ k�� ����
        if(arr[v[i]] == 0){
            arr[v[i]]++;
            result++;
            max_value = max(result, max_value);
        }
        else
            arr[v[i]]++;
    }
    for(int i = 0; i < n; i++){             
        if(arr[v[i%n]] == 1){                       //���� �տ��� ����
            arr[v[i%n]]--;
            result--;
        }
        else
            arr[v[i%n]]--;
        if(arr[v[(i+k)%n]] == 0){                   //���� �ڿ� �߰�
            arr[v[(i+k)%n]]++;
            result++;
            max_value = max(result, max_value);
        }
        else
            arr[v[(i+k)%n]]++;
    }
    printf("%d", max_value);
}