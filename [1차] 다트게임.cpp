#include <string>
#include <cmath>
using namespace std;

int cal(int num, char c){
    printf("%d %c\n", num, c);
    if(c == 'S')
        return num;
    if(c == 'D')
        return num*num;
    if(c == 'T')
        return num*num*num;
}

int solution(string dartResult) {
    int answer = 0;
    int first, second, third;
    int index = 1;
    //ù��°
    int n;
    if(dartResult[index] == '0'){
        n = 10;
        index++;
    }
    else
        n = dartResult[0] - '0';
    first = cal(n, dartResult[index]);
    if(dartResult[index+1] == '*'){    
        first *= 2;
        index++;
    }
    if(dartResult[index+1] == '#'){
        first *= -1;
        index++;
    }
    index++;
    //�ι�°
    if(dartResult[index+1] == '0'){
        n = 10;
        index++;
    }
    else
        n = dartResult[index] - '0';
    second = cal(n, dartResult[index+1]);
    index += 2;
    if(dartResult[index] == '*'){
        first *= 2;
        second *= 2;
        index++;
    }
    if(dartResult[index] == '#'){
        second *= -1;
        index++;
    }
    //����°
    if(dartResult[index+1] == '0'){
        n = 10;
        index++;
    }
    else
        n = dartResult[index] - '0';
    third = cal(n, dartResult[index+1]);
    if(dartResult.size() - index == 3){                 //���������� �ɼ��� �ִٸ�
        index += 2;
        if(dartResult[index] == '*'){
            second *= 2;
            third *= 2;
        }
        if(dartResult[index] == '#')
            third *= -1;
    }
    printf("%d %d %d", first, second, third);
    answer = first + second + third;
    return answer;
}