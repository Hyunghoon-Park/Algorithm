#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp;
    vector<string> v;
    stringstream stream;
    stream.str(s);
    while(stream >> tmp)
        v.push_back(tmp);
    vector<int> num;
    for(int i = 0; i < v.size(); i++)
        num.push_back(stoi(v[i]));
    sort(num.begin(), num.end());
    printf("%d", num.size());
    answer += to_string(num[0]);
    answer += " ";
    answer += to_string(num[num.size()-1]);
    return answer;
}