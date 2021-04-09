#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    int height = 3;
    for(;;height++){
        if(sum % height == 0){  //높이로 나누어 떨어지면
            int width = sum / height;
            if(((width-2) * (height-2)) == yellow){
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}