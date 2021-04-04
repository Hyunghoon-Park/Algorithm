#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++) {
        vector <int> temp;
        for(int j = 0; j < skill_trees[i].size(); j++) {        // skill_trees 중에 skill에 없는 skill을 제외하고 temp에 저장
            for(int k = 0; k < skill.size(); k++) {
                if(skill[k] == skill_trees[i][j]) {
                    temp.push_back(skill_trees[i][j]);
                }
            }
        }
        int flag = 0;
        for(int j = 0; j < temp.size(); j++) {  // temp의 길이만큼 skill을 비교하여 순서가 일치하는지 확인
            if(temp[j] != skill[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0)     // 일치하면 answer값 1증가
            answer++;
    }
    return answer;
}