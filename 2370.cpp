#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
int input[10000][2];
int arr[20000] = {0,};
int result = 0;
vector<int> location;
set<int> s;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &input[i][0], &input[i][1]);
        if(find(location.begin(), location.end(), input[i][0]) - location.begin() == location.size())   //input[i][0]이 존재하지 않는다면
            location.push_back(input[i][0]);
        if(find(location.begin(), location.end(), input[i][1]) - location.begin() == location.size())   //input[i][0]이 존재하지 않는다면
            location.push_back(input[i][1]);
    }
    sort(location.begin(), location.end());
    for(int i = 0; i < n; i++){
        int x = find(location.begin(), location.end(), input[i][0]) - location.begin(); //해당 숫자들의 벡터상의 인덱스 값
        int y = find(location.begin(), location.end(), input[i][1]) - location.begin();
        for(int j = x; j <= y; j++)
            arr[j] = i;
    }
    for(int i = 0; i < location.size(); i++)
        s.insert(arr[i]);
    printf("%d", s.size());
}