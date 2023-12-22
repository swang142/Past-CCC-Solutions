#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

ll N, M;      


struct Cell{
    int r, c;
    Cell(int r, int c){
        this -> r= r;
        this-> c= c;
    }
    Cell(){
        
    }
};


vector<vector<Cell>> vals(1000010);
bool visited[1010][1010];

string bfs(Cell last){
    queue<Cell> q;    
    q.push(last);
    visited[last.r][last.c]= true; 


    while(!q.empty()){
        Cell current= q.front();
        q.pop();


        vector<Cell> neighbours= vals[+ current.r * current.c];

        for(auto neighbour: neighbours){
            if(neighbour.r== 1 && neighbour.c ==1){
                return "yes";
            }
            else if(!visited[neighbour.r][neighbour.c]){
                q.push(neighbour);
                visited[neighbour.r][neighbour.c]= true;
            }
        }
    }

    return "no";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
 
    cin >> M >> N;
    
    Cell last(M, N);
    
    for(int i=1; i<= M; i++){
        for(int j=1; j<= N; j++){
            ll curV; cin>> curV;
            Cell c(i, j);
            vals[curV].push_back(c);
        }
    }



    cout << bfs(last) << endl;

}