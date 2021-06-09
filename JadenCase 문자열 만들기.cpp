#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool space_check = true;
    for(int i = 0; i < s.length(); i++){
        if(space_check && 'a' <= s[i] && s[i] <= 'z')  //첫번째이고 소문자이면 대문자로
            s[i] -= 32;
        else if(!space_check && 'A' <= s[i] && s[i] <= 'Z')
            s[i] += 32;
        space_check = false;
        if(s[i] == ' ')
            space_check = true;
        answer += s[i];
    }
    return answer;
}

/*  //실패한 stringstream을 활용한 풀이
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp;
    vector<string> v;
    stringstream stream;
    stream.str(s);
    while(stream >> tmp)
        v.push_back(tmp);
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(j == 0 && 'a' <= v[i][j] && v[i][j] <= 'z')
                v[i][j] -= 32;
            else if('A' <= v[i][j] && v[i][j] <= 'Z')
                v[i][j] += 32;
            answer += v[i][j];
        }
        answer += " ";
    }
    answer.pop_back();
    return answer;
}*/