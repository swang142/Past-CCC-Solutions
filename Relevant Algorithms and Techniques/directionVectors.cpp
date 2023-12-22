#include <iostream>
using namespace std;
#include <unordered_map>

typedef long long ll;

//define direction vectors
int dr[4]= {-1, 1, 0, 0};
int dc[4]= {0, 0, -1, 1};

for(int i=0; i<4; i++){
    neighbourR= r+ dr[i];
    neighbourC= c+ dc[i];

    //skip invalid cells

    if(neighbourR <0 || neighbourR>= numRows) continue;
    if(neighbourC <0 || neighbourC>= numCols) continue;

    neighbour= grid[neighbourR][neighbourC;
    //... do evaluation
}

