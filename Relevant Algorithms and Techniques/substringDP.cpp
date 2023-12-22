#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<string, bool> memo;

bool canConstruct(string target, vector<string> wordBank){
    if(memo.find(target)!= memo.end()){
        return memo[target];
    }
    if(target.size() == 0){
        return true;
    }

    for(auto val: wordBank){
        if(target.find(val)== 0){ //must be a prefix, or else doesnt work
            string t= target.substr(val.size()); //remove the val from the current target
            if(canConstruct(t, wordBank)== true){
                memo[target]= true;
                return true;
            }
        }
    }
    memo[target]= false;
    return false;
}

bool canConstructIter(string target, vector<string> wordBank){
    vector<bool> table;
    table.assign(target.size() +1, 0);
    table[0]= true;

    for(int i=0; i<target.size(); i++){
        if(table[i]){
            for(auto val: wordBank){
                if(target.substr(i, val.size()) == val){ //c++ subtr returns from the index to the end of the string when out of bounds
                    table[i+val.size()]= true; //returns if we can get the word just under position i+val.size()

                }
            }
        }

    }

    return table[target.size()];
}

unordered_map<string, int> memo1;

int countConstruct(string target, vector<string> wordBank){
    if(memo1.find(target)!= memo1.end()){
        return memo1[target];
    }
    if(target.size() == 0){
        return 1;
    }
    int total=0;

    for(auto val: wordBank){
        if(target.find(val)== 0){ //must be a prefix, or else doesnt work
            string t= target.substr(val.size()); //remove the val from the current target
            total+= countConstruct(t, wordBank);
        }
    }
    memo1[target]= total;
    return total;
    
}

int countConstructIter(string target, vector<string> wordBank){
    vector<int> table;

    table.assign(target.size() +1, 0);
    table[0]= 1;

    for(int i=0; i<target.size(); i++){
        if(table[i]){
            for(auto val: wordBank){
                if(target.substr(i, val.size()) == val){ //c++ subtr returns from the index to the end of the string when out of bounds
                    table[i+val.size()]+= table[i]; ////returns how many times we can get the word just under position i+val.size()
                }
            }
        }

    }

    return table[target.size()];
}

unordered_map<string, vector<vector<string>>> memo3;

vector<vector<string>> allConstruct(string target, vector<string>& wordBank){
    vector<vector<string>> v;
    if(memo3.find(target)!= memo3.end()){
        return memo3[target];
    }
    if(target.size() == 0){
        v= {{}};
        return v;   
    }
    for(auto val: wordBank){
        if(target.find(val) == 0){
            string t= target.substr(val.size());
            auto c= allConstruct(t, wordBank);
            for(auto& list: c){  
                list.insert(list.begin(), val);
                v.push_back(list);
            } 
        }
    }
    memo3[target]= v;
    return v;
}

vector<vector<string>> allConstructIter(string target, vector<string>& wordBank){
    vector<vector<vector<string>>> table;

    table.assign(target.size() +1, {});
    table[0]= {{}};


    for(int i=0; i<target.size(); i++){
        if(!table[i].empty()){
            for(auto val: wordBank){
                if(target.substr(i, val.size()) == val){ //c++ subtr returns from the index to the end of the string when out of bounds
                    auto d= table[i]; 
                    for(auto list: d){
                        list.push_back(val);
                        table[i+ val.size()].push_back(list);
                    }
                }
            }
        }

    }

    return table[target.size()];
}

int main(){

    vector<string> wb= {"a", "aa", "aaa"};
    bool g= canConstructIter("abcdef", wb);
    cout << g << endl;

   int f= countConstructIter("abcdef", wb);
   cout << f << endl;

   auto d= allConstructIter("abcdef", wb);

   for(auto f: d){
       for(auto l: f){  
           cout << l << " ";
       }
       cout << endl;
   }
    


}