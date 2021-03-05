#include <iostream>
#include <algorithm>

using namespace std;

int x, y, w, h, dis;

int main(){
    scanf("%d %d %d %d", &x, &y, &w, &h);
    if(x > w / 2)
        dis = w - x;
    else
        dis = x;
    if(y > h / 2)
        dis = min(dis, h - y);
    else
        dis = min(dis, y);
    printf("%d", dis);
}