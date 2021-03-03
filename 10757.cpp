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
    while(str1.length() < str2.length())    //str1�� ���̰� ª�ٸ� str2���� ���̸�ŭ 0�߰�
        str1 += '0';
    while(str1.length() > str2.length())    //str2�� ���̰� ª�ٸ� str1���� ���̸�ŭ 0�߰�
        str2 += '0';
    for(int i = 0; i < str1.length(); i++){
        int tmp = (str1[i]-'0' + str2[i]-'0' + up);
        up = tmp/10;
        result += to_string(tmp % 10);
    }
    if(up == 1)         //�������� �ø����� 1�� ���� ��
        result += '1';
    reverse(result.begin(), result.end());
    cout << result;
}