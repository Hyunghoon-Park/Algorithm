#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int v_long, v_short, up = 0;
string str1, str2;
string result;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> str1 >>str2;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    while(str1.length() < str2.length())    //str1의 길이가 짧다면 str2과의 차이만큼 0추가
        str1 += '0';
    while(str1.length() > str2.length())    //str2의 길이가 짧다면 str1과의 차이만큼 0추가
        str2 += '0';
    for(int i = 0; i < str1.length(); i++){
        int tmp = (str1[i]-'0' + str2[i]-'0' + up);
        up = tmp/10;
        result += to_string(tmp % 10);
    }
    if(up == 1)         //마지막에 올림수가 1이 있을 때
        result += '1';
    reverse(result.begin(), result.end());
    cout << result;
}