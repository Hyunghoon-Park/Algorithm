#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    for(int i = 0; i < new_id.length(); i++)    //1단계
        if('A' <= new_id[i] && new_id[i] <= 'Z')
                new_id[i] = tolower(new_id[i]);
    for(int i = 0; i < new_id.length();){       //2단계
        if(('a' <= new_id[i] && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            i++;
            continue;
        }
        new_id.erase(new_id.begin() + i);
    }
    for(int i = 0; i < new_id.length()-1;){       //3단계
        if(new_id[i] == '.' && new_id[i] == new_id[i+1])
            new_id.erase(new_id.begin() + i);
        else
            i++;
    }
    if(new_id[0] == '.')                          //4단계
        new_id.erase(new_id.begin());
    if(new_id[new_id.length()-1] == '.')
        new_id.erase(new_id.end()-1);
    if(new_id.length() == 0)                      //5단계
        new_id += "a";
    if(new_id.length() > 15){                     //6단계
        new_id.erase(15);
        if(new_id[14] == '.')
            new_id.erase(new_id.end()-1);
    }
    if(new_id.length() <= 2)                      //7단계
        while(new_id.length() < 3)
            new_id += new_id[new_id.length() -1];
    
    
    return new_id;
}