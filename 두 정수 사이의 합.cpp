#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a == b)
        answer = a;
    else{
        int min_value = min(a, b);
        int max_value = max(a, b);
        for(long long i = min_value; i <= max_value; i++){
            answer += i;
        }
    }
    return answer;
}