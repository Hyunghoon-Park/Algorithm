#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index;
bool compare(string s1, string s2){
    if(s1[index] != s2[index])
        return s1[index] < s2[index];
    else
        return s1 < s2;
        
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    index = n;
    sort(strings.begin(), strings.end(), compare);
    answer = strings;
    return answer;
}