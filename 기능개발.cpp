#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int tmp = 0;

    while(tmp < progresses.size()){
        for(int i = 0; i < progresses.size(); i++){
                progresses[i] += speeds[i];
        }
        int clearcount = 0;
        if(progresses[tmp] >= 100){
            while(progresses[tmp] >= 100 && tmp < progresses.size()){
                    clearcount++;
                    tmp++;
            }
            answer.push_back(clearcount);
        }
    }
    return answer;
} 