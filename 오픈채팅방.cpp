#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,string>> list;
    map<string, string> m;
    for(int i = 0; i < record.size(); i++){
        stringstream stream;
        string tmp;
        stream.str(record[i]);
        vector<string> v;
        while(stream >> tmp)
            v.push_back(tmp);
        if(v[0] != "Change")
            list.push_back({v[0], v[1]});
        if(v[0] != "Leave"){
            if(m.find(v[1]) == m.end())
                m.insert({v[1],v[2]});
            else
                m[v[1]] = v[2];
        }
    }
    for(int i = 0; i < list.size(); i++){
        string tmp = m[list[i].second];
        if(list[i].first == "Enter")
            tmp += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        else
            tmp += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        answer.push_back(tmp);
    }
    return answer;
}