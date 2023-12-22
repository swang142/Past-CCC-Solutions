#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<string, int> ingredients;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

     while(t--){
         cin.ignore();
         string title; getline(cin, title);
         cout << title << '\n';
        
         int m; cin >> m; 
         int n; cin >> n;
         int b; cin >> b;

         for(int i=0; i< m; i++){
             string ingName; cin >>ingName;
             int c; cin >> c;
             ingredients[ingName]= c;
         }

         cout << "b" << title << '\n';

         bool y= false;

         for(int i=0; i< n; i++){
             cin.ignore();
             string recipe; getline(cin, recipe);
             int k; cin>>k;
             int cost=0;
            for(int j=0; j<k; j++){
                string ingName; cin>> ingName;
                int x; cin >> x;
                cost+= ingredients[ingName]*x;
            }

            if(cost <= b){
                cout << "b: " <<recipe << '\n';
                y= true;
            }

         }

         if(!y) cout << "too expensive" << endl;




     }

}