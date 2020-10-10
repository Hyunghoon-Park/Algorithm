#include <iostream>
int main(void){
    int num, sum = 0, remainderArr[42] = {0,};
    for(int i = 0; i < 10; i++){
        std::cin>>num;
        if(!remainderArr[num % 42]++)
            sum++;
    }
    std::cout<<sum;
}