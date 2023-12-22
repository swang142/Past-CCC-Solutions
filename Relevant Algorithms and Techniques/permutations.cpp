
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void permutate(vector<int>& list, vector<bool>& alrSelected, vector<int>& permutation){

    if(permutation.size() == list.size()){ // our current permuatation is complete
        for(auto a: permutation) cout << a << " "; //prints current permutation
        cout << '\n';
        return;
    }

    for(int i=0; i< list.size(); i++){
        //the selected list position corresponds with the element's position in the list.
        if(!alrSelected[i]){ //if our current element has not been selected yet
            permutation.push_back(list[i]); //we select it
            alrSelected[i]= true; //mark the current element as selected

            permutate(list, alrSelected, permutation); //recur

            //like clearing a maze position after a dead end- this clears our current element when we have to backtrack
            permutation.pop_back();
            alrSelected[i] = false;

        }
    }
}

void generatePermutations(vector<int>& list){
    vector<int> permutation= {}; //our current permutation starts empty

    vector<bool> alrSelected= {};
    for(int i=0; i< list.size(); i++){
        alrSelected.push_back(false); //none of the elements have been selected yet.
    }

    permutate(list, alrSelected, permutation);

}

void generatePermutations2(vector<int>& list){
    vector<int> permutation= {};
    for(auto a: list){
        permutation.push_back(a);
    }

    do{
        for(auto a: permutation) cout << a << " "; //prints current permutation
        cout << '\n';
    }while (next_permutation(permutation.begin(),permutation.end()));

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> list= {1,10, 2, 58};

    generatePermutations(list);




}