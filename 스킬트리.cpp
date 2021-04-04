#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++) {
        vector <int> temp;
        for(int j = 0; j < skill_trees[i].size(); j++) {        // skill_trees �߿� skill�� ���� skill�� �����ϰ� temp�� ����
            for(int k = 0; k < skill.size(); k++) {
                if(skill[k] == skill_trees[i][j]) {
                    temp.push_back(skill_trees[i][j]);
                }
            }
        }
        int flag = 0;
        for(int j = 0; j < temp.size(); j++) {  // temp�� ���̸�ŭ skill�� ���Ͽ� ������ ��ġ�ϴ��� Ȯ��
            if(temp[j] != skill[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0)     // ��ġ�ϸ� answer�� 1����
            answer++;
    }
    return answer;
}