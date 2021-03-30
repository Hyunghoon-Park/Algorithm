#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;  //minheap

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n*n; i++){
        int input;
        scanf("%d", &input);
        if(pq.size() == n){
            if(pq.top() < input){
                pq.pop();
                pq.push(input);
            }
        }
        else
            pq.push(input);
    }
    printf("%d", pq.top());
}