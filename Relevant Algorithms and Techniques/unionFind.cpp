#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, string> parents;
unordered_map<string, int> setSizes;

string find(string node){
    if(parents[node]== node){
        return node;
    }

    parents[node]= find(parents[node]);
    return parents[node];
}

void Union(string x, string y){
    string rootX= find(x);
    string rootY= find(y);
    if(rootX!= rootY){
        if(setSizes[rootX] < setSizes[rootY]){
            parents[rootX]= rootY;
            setSizes[rootY]+= setSizes[rootX];
        }
        else{
            parents[rootX]= rootY;
            setSizes[rootX]+= setSizes[rootY];
        }
    }

}

int main(){

    for(string node: nodes){
        parents[node]= node;
    }

}