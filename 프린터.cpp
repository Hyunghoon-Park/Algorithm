#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, count = 0;
    queue<pair<int,int>> q;
    priority_queue <int> pq;
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    while(!q.empty()){
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        if(pq.top() == value){       //같으면
            pq.pop();
            count++;
            if(index == location)
                break;
        }
        else{                       //다르면
            q.push({index, value});
        }
    }
    answer = count;
    return answer;
}