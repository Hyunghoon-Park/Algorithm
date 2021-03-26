#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a,pair<double, int> b){      //비교함수
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> sucess(N+1);
    vector<double> fail(N,0.0);
    vector<pair<double,int>> p;
    sort(stages.begin(), stages.end());
    double index = stages.size();
    
    for(int i = 0; i < stages.size(); i++)
        sucess[stages[i]-1]++;                  //각 스테이지에 머무르는사람 숫자 저장
    for(int i = 0; i < N; i++){
        if(index == 0)                          //예외처리, 아무도 스테이지에 도달하지 못하였을때
            fail[i] = 0.0;
        else{
            fail[i] = sucess[i] / index;        //실패율 저장
            index -= sucess[i];
        }
    }
    for(int i = 0; i < N; i++)
        p.push_back({fail[i],i+1});             //실패율과 해당 index pair에 저장
    sort(p.begin(), p.end(), compare);          //compare()함수 만들어 정렬
    for(int i = 0; i < N; i++)
        answer.push_back(p[i].second);          
    return answer;
}