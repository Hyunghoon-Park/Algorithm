#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, idx = 0;
    sort(people.begin(), people.end());
    while(people.size() > idx){
        int heavy = people.back();
        people.pop_back();
        if(heavy + people[idx] <= limit){
            idx++;
            answer++;
        }
        else
            answer++;
    }
    return answer;
}