#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int y = arr1.size();
    int x = arr1[0].size();
    int z = arr2[0].size();
    int tmp = 0, sum;
    for(int i  = 0; i < y; i++){
        vector <int> vec;
        for(int k = 0; k < z; k++){
            sum = 0;
            for(int j = 0; j < x; j++)
                sum += arr1[i][j] * arr2[j][k];
            vec.push_back(sum);
        }
        answer.push_back(vec);
    }
    return answer;
}