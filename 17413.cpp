#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> s;
bool check = false;
int main(){
    getline(cin, str);
    str += '\n';

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '<'){
            check = true;
            if(!s.empty()){
                int tmp = s.size();
                for(int j = 0; j < tmp; j++){
                    printf("%c", s.top());
                    s.pop();
                }
            }
        }
        if(check){
            printf("%c", str[i]);
        }
        else
        {
            s.push(str[i]);
        }
        if(str[i] == '>'){
            check = false;
        }
        if(!check && str[i] == ' '){
            s.pop();
            int tmp = s.size();
            for(int j = 0; j < tmp; j++){
                printf("%c", s.top());
                s.pop();
            }
            printf("%c", ' ');
        }
        if(!check && str[i] == '\n'){
            s.pop();
            int tmp = s.size();
            for(int j = 0; j < tmp; j++){
                printf("%c", s.top());
                s.pop();
            }
        }
        
    }
    return 0;
}