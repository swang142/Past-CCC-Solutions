    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

int inf= 1e9;
int N;

int dr[4]= {-1, 1, 0, 0};
int dc[4]= {0, 0, -1, 1};

vector<vector<bool>> visited;

vector<vector<int>>grid(3, vector<int>(3, 0));

void fillR(int r, int c){
    if(c==0 && grid[r][1]!= inf && grid[r][2] != inf){
        grid[r][c]= grid[r][1]- (grid[r][2]- grid[r][1]);
    }
    else if(c== 1 && grid[r][0]!= inf && grid[r][2] != inf){
        grid[r][c]= (grid[r][0]+ grid[r][2])/2;
    } 
    else if(c == 2 && grid[r][1]!= inf && grid[r][0] != inf){
        grid[r][c]= grid[r][1]+(grid[r][1]- grid[r][0]);
    }
}

void fillC(int r, int c){
    if(r==0 && grid[1][c]!= inf && grid[2][c] != inf){
        grid[r][c]= grid[1][c]- (grid[2][c]- grid[1][c]);
    }
    else if(r== 1 && grid[0][c]!= inf && grid[2][c] != inf){
        grid[r][c]= (grid[0][c]+ grid[2][c])/2;
    } 
    else if(r == 2 && grid[1][c]!= inf && grid[0][c] != inf){
        grid[r][c]= grid[1][c]+(grid[1][c]- grid[0][c]);
    }
}


void explore(int r, int c){
    

    if(r <0 || r> 2) return; if(c < 0 || c>2) return;
    if(grid[r][c] != inf)return;
    else{

        fillR(r, c);
        fillC(r, c);
    }

 //   visited[r][c]= true;

    for(int i=0; i< 4; i++){
        int nR= r+ dr[i], nC= c+ dc[i];
        if(nR >=0 && nR <3 && nC>= 0 && nC <3 ){
            explore(nR, nC);
        }
    }

}

int main(){

    for(int i=0; i< 3; i++){
        for(int j=0; j< 3; j++){
            string d; cin>> d;
            int in;
            if(d == "X") in= inf;
            else in = stoi(d);
            grid[i][j]= in;
        }
    }

    for(int i=0; i< 3; i++){
        for(int j=0; j< 3; j++){
           // visited.assign(3, vector<bool>(3, false));
            explore(i, j);
        }
    }

    for(int i=0; i< 3; i++){
        for(int j=0; j< 3; j++){
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }






}

