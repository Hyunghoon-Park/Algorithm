#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
int count_num;
char arr[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
char line[8] = {NULL,};
bool check[8] = {false,};
void dfs(int index, vector<string> data){
    if(index == 8){
        for(int i = 0; i < data.size(); i++){
            char c = data[i][3];
            int dis = data[i][4] - '0' + 1;
            int index1 = -1;
            int index2 = -1;
            for(int j = 0; j < 8; j++){
                if(line[j] == data[i][0])
                    index1 = j;
                if(line[j] == data[i][2])
                    index2 = j;
                if(index1 != -1 && index2 != -1)
                    break;
            }
            if(c == '='){
                if(abs(index1 - index2) != dis)
                    return;
            }
            else if(c == '<'){
                if(abs(index2 - index1) >= dis)
                    return;
            }
            else if(c == '>'){
                if(abs(index2 - index1) <= dis)
                    return;
            }
        }
        count_num++;
        return;
    }
    for(int i = 0; i < 8; i++){
        if(check[i] == false){
            line[index] = arr[i];   //i번째 친구를 줄 index번째에 세움
            check[i] = true;            //i번째 친구 check
            dfs(index+1, data);
            check[i] = false;           //i번쨰 친구 원상복구
        }
    }
}

int solution(int n, vector<string> data) {
    count_num = 0;
    dfs(0, data);
    return count_num;
}