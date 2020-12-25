#include <iostream>
#include <stack>
using namespace std;

int n;
double value;
stack<double> s;
double alph[27] = {0};

int main() {
  double tmp1, tmp2;
  scanf("%d", &n);
  string str;
  cin >> str;
  for(int i = 0; i < str.size(); i++){
    if('A' <= str[i] && str[i] <= 'Z'){
      if(alph[str[i] - 65] == 0){
        scanf("%lf", &value);
        alph[str[i] - 65] = value;
      }
      else{
        value = alph[str[i] - 65];
      }
      s.push(value);
    }
    else{
      if(str[i] == '+'){
        tmp1 = s.top();
        s.pop();
        tmp2 = s.top();
        s.pop();
        s.push(tmp2 + tmp1);
      }
      else if(str[i] == '*'){
        tmp1 = s.top();
        s.pop();
        tmp2 = s.top();
        s.pop();
        s.push(tmp2 * tmp1);
      }
      else if(str[i] == '-'){
        tmp1 = s.top();
        s.pop();
        tmp2 = s.top();
        s.pop();
        s.push(tmp2 - tmp1);
      }
      else if(str[i] == '/'){
        tmp1 = s.top();
        s.pop();
        tmp2 = s.top();
        s.pop();
        s.push(tmp2 / tmp1);
      }
    }
  }
  printf("%.2lf", s.top());
  return 0;
}