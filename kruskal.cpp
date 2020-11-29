#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int set_pointer[5] = {1,2,3,4,5};
int set_depth[5] = {0};

class E{
    public:
    int node[2];
    int dis;
    E(int a, int b, int dis){
        this -> node[0] = a;
        this -> node[1] = b;
        this -> dis = dis;
    }
    bool operator<(E &e){
        return this-> dis < e.dis;
    }
};
vector<E> v;
vector<E> F;
int find(int a){
    if(set_pointer[a-1] == a)
        return a;
    find(set_pointer[a-1]);
}
void merge(int a, int b){
    if(set_depth[a-1] != set_depth[b-1]){
        if(set_depth[a-1] > set_depth[b-1]){
            set_pointer[b-1] = a;
        }
        else{
            set_pointer[a-1] = b;
        }
    }
    else{
        if(a < b){
            set_pointer[b-1] = a;
            set_depth[a-1]++;
        }
        else{
            set_pointer[a-1] = b;
            set_depth[b-1]++;
        }
        
    }
}
void kruskal(int n, int m){
    int set_pointer[5] = {1,2,3,4,5};
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        int a = find(v[i].node[0]);
        int b = find(v[i].node[1]);
        if(!(a == b)){
            merge(a,b);
            F.push_back(v[i]);
        }
    }
}
int main(){
    int n = 5;
    int m = 7;
    v.push_back(E(1,2,1));
    v.push_back(E(1,3,3));
    v.push_back(E(2,3,3));
    v.push_back(E(2,4,6));
    v.push_back(E(3,4,4));
    v.push_back(E(3,5,2));
    v.push_back(E(4,5,5));
    kruskal(n,m);
    printf("***С§Че F***\n");
    for(int i = 0; i < F.size(); i++)
        printf("V%d V%d    %d\n", F[i].node[0], F[i].node[1], F[i].dis);
    return 0;
}