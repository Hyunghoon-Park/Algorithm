#include <iostream>

using namespace std;

int x, i;

int main(){
	scanf("%d", &x);
	for(i = 1; x > 0; i++)
	    x -= i;
	if(i % 2 == 1)
        printf("%d/%d", i+(x-1), 1 - x);
	else if (i % 2 == 0)
        printf("%d/%d", 1 - x, i+(x-1));
}