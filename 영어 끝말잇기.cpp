#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    int arr[10] = {0,};
    int check = true;
    int people = -1;
    int last = words[0][words[0].length()-1];
    arr[0] = 1;
    s.insert(words[0]);
    for(int i = 1; i < words.size(); i++){
        int first = words[i][0];
        arr[i%n]++;
        if(last == first){                          
            last = words[i][words[i].length()-1];
        }
        else{
            people = i % n;
            check = false;
        }
        if(s.find(words[i]) != s.end()){
            people = i % n;
            check = false;
        }
        if(words[i].size() == 1){
            people = i % n;
            check = false;
        }
        s.insert(words[i]);
        if(check == false)
            break;
    }
    if(check == false){
        answer.push_back(people+1);
        answer.push_back(arr[people]);
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}