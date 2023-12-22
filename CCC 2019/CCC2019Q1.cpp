#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

string N;

vector<vector<int>> grid= {
    {1 ,2},
    {3,4}
    };


void vF(){
    int p0= grid[0][0], p1= grid[1][0];
    grid[0][0]= grid[0][1]; grid[1][0]= grid[1][1];
    grid[0][1]= p0; grid[1][1]= p1;
}
void hF(){
    int p0= grid[0][0], p1= grid[0][1];
    grid[0][0]= grid[1][0]; grid[0][1]= grid[1][1];
    grid[1][0]= p0; grid[1][1]= p1;
}

int main(){
    cin >> N;

    for(char c: N){
        if(c == 'V') vF();
        else hF();
    }

    for(auto a: grid){
        for(int b: a){
            cout << b << " ";
        }
        cout << endl;
    }

}