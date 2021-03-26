#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a,pair<double, int> b){      //���Լ�
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
        sucess[stages[i]-1]++;                  //�� ���������� �ӹ����»�� ���� ����
    for(int i = 0; i < N; i++){
        if(index == 0)                          //����ó��, �ƹ��� ���������� �������� ���Ͽ�����
            fail[i] = 0.0;
        else{
            fail[i] = sucess[i] / index;        //������ ����
            index -= sucess[i];
        }
    }
    for(int i = 0; i < N; i++)
        p.push_back({fail[i],i+1});             //�������� �ش� index pair�� ����
    sort(p.begin(), p.end(), compare);          //compare()�Լ� ����� ����
    for(int i = 0; i < N; i++)
        answer.push_back(p[i].second);          
    return answer;
}