#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(int a, int b){ //remember, returns whether a < b
    return !(a<b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v= {1,2,3,4,5,6,7};

    set<int, decltype(&comp)> numsSet(comp); //needs both the decltype(&comp) and (comp)
    map<int, string, decltype(&comp)> numsMap(comp);
    priority_queue<int, vector<int>, decltype(&comp)> numsQueue(comp); //priority queue needs the vector parameter too for the template for some reason

    for(int n: v){
        numsSet.insert(n);
        numsMap[n]= "bruh";
        numsQueue.push(n);
    }

    for(auto d: numsSet){
        cout << d << " ";
    }

        cout << '\n';

    for(auto d: numsMap){
        cout << "(" << d.first << ", " << d.second << ")  ";
    }

        cout << '\n';

    while(!numsQueue.empty()){
        cout << numsQueue.top() << " ";
        numsQueue.pop();
    }

}