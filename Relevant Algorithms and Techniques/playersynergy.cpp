#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector< vector<ll> > allSubsets;

void generateAllSubsets(ll index, ll elements[], const ll size, vector<ll> subset) {

  if(index == size){
      allSubsets.push_back(subset);
      return;
  }

  // Not Including Value which is at Index

 generateAllSubsets(index+1,  elements, size, subset);


  //Including Value which is at Index
  subset.push_back(elements[index]);
  generateAllSubsets(index+1, elements, size, subset);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll p; cin >> p;

    ll arr[p];

    for(ll i=0; i<p ;i++){
        cin >> arr[i];
    }

    vector<ll> subsets;


    generateAllSubsets(0, arr, p, subsets);

    ll maxProduct=1;

    for(int i=0; i< allSubsets[1].size(); i++){
        maxProduct*= (allSubsets[1])[i];
    }



    for(vector<ll> subset: allSubsets){

        if(subset.size()!=0){
            ll product= 1;
            for(ll i=0; i< subset.size(); i++){
                product*= subset[i];
            }

            maxProduct= max(maxProduct, product);
        }

    }

    cout << maxProduct << '\n';
}