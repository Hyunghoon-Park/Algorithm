#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int idx = 1; idx <= n; idx++){
        int sum = 0;
        for(int i = idx;;i++){
            sum += i;
            if(sum == n){
                answer++;
                break;
            }
            if(sum > n)
                break;
        }
    }
    return answer;
}