#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int arr[201] = {0,};
    for(int i = 0; i < numbers.size()-1; i++)
        for(int j = i+1; j < numbers.size(); j++)
            arr[numbers[i] + numbers[j]]++;
    for(int i = 0; i <= 200; i++)
        if(arr[i] > 0)
            answer.push_back(i);
    return answer;
}