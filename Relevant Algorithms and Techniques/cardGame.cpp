
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> cards;
vector<bool> used;
vector<bool> lettersUsed;
string firstCard;

//every card is a string "'blueLetter''redLetter'"


int solve(int index, string lastCard){
    //combo has been made, return the size of our combo
    if(lastCard[1] == firstCard[0]){
        return index;
    }

    int ret= -1;
    //otherwise, expand the current combo with all possible next cards

    for(int i=0; i<cards.size(); i++){
        string curCard= cards[i];

        if(!used[i] && !lettersUsed[curCard[0] - 65] && lastCard[1]== curCard[0]){ 
        //pruning bad cases: the current card must not have been used, and the blue letter must not have been used (no same blue letter)
        // Most importantly, the red letter of our last card must match the blue letter of the current card for our current card to become the new last card

            used[i]= true; //current card has been used
            lettersUsed[curCard[0]-65]= true; //blue letter of current card has been used

            ret= max(ret, solve(index+1,curCard)); //recur

            //backtracking
            used[i]= false;
            lettersUsed[curCard[0]-65]= false;
        }
    }

    return ret;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int t; cin>> t;

    while(t--){
        int N; cin >>N;

        cards= vector<string>(N);
        for(int i=0; i<N; i++) cin>> cards[i];
        
        for(int i=0; i<cards.size(); i++) used.push_back(false);

        int rec= -1;
        
        //try all possible cards as the first in the combo
        for(int i=0; i< cards.size(); i++){
            lettersUsed.clear(); //lettersUsed is bool vector that assigns true/false values to each letter position
            for(int i=0; i< 26; i++) lettersUsed.push_back(false);

            used[i]= true; //the current card has been used
            firstCard= cards[i];    
            lettersUsed[firstCard[0] - 65]= true; //blue letter of first card has been used

            rec= max(rec, solve(1, cards[i])); //finds longest combo
            
            //backtrack
            used[i]= false; 
            lettersUsed[firstCard[0] - 65]= false;
            
        }

        cout << rec << '\n';
    }    



}