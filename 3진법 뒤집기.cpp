#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> three;
    while(n > 0){
        three.push_back(n % 3);
        n /= 3;
    }
    reverse(three.begin(), three.end());
    for(int i = 0; i < three.size(); i++)
        answer += (three[i] * pow(3,i));
    return answer;
}