#include <string>
#include <vector>

using namespace std;

int countone(int num){
    int result = 0;
    while(num > 0){
        if(num % 2 == 1)
            result++;
        num = num / 2;
    }
    return result;
}
int solution(int n) {
    int answer = 0, count = 0;
    count = countone(n);
    while(1){
        int tmp = countone(++n);
        if(tmp == count){
            answer = n;
            break;
        }
    }
    return answer;
}