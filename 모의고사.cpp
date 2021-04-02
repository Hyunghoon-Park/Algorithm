#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int max_score = 0;
    int math1[] = {1, 2, 3, 4, 5};
    int math2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int math3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int score[3] = {0,};
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == math1[i%5])
            score[0]++;
        if(answers[i] == math2[i%8])
            score[1]++;
        if(answers[i] == math3[i%10])
            score[2]++;
    }
    max_score = max(max(score[0], score[1]), score[2]);
    for(int i = 0; i < 3; i++){
        if(score[i] == max_score)
            answer.push_back(i + 1);
    }
    return answer;
}