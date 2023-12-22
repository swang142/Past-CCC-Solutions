
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void subsets(vector<int>& list, int index, vector<int>& subset){
    if(index == list.size()){ //our current subset is complete
        for(int a: subset) cout << a << " ";
        cout << '\n';
        return;
    }

    //skip the current element
    subsets(list, index+1, subset);

    //adds the current element
    subset.push_back(list[index]);
    subsets(list, index+1, subset);

    //like clearing a maze position after a dead end- this clears our current element from the subset when we backtrack
    subset.pop_back();

}

void generateSubsets(vector<int>& list){
    int index=0; //index starts at 0
    vector<int> subset= {}; //our current subset starts empty
    subsets(list, index, subset);

}

void generateSubsets2(vector<int>& list){
    int n= list.size();
     /* Run counter i from 000..0 to 111..1*/
    for (int i = 0; i < (int) pow(2, n); i++){
        vector<int> subset= {}; //our current subset starts empty

 
        // consider each element in the set
        for (int j = 0; j < n; j++){

            // Check if jth bit in the i is set (on/1). If the bit
            // is set (on/1), we consider jth element from set
            if ((i & (1 << j)) != 0)
                subset.push_back(list[j]);
        }

        for(int a: subset) cout << a << " ";
        cout << '\n';

    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, string> a;
    cout << a["bruh"] << endl;

}