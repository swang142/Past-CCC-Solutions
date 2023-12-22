#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int inf= 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n,c; cin >> n >> c;
    int freq[10000];
    vector<int> pList;
    
    for(int i=0; i< n; i++){
        int p; cin >> p;
        freq[p]++;   if(freq[p]==1) pList.push_back(p);
    }

    sort(pList.begin(), pList.end());

    int count=0;

      for(int i=0; i< pList.size() ; i++ ){
        for(int j=i+1; j< pList.size(); j++){
            int a, b; a= pList[i]; b= pList[j]; 
            if(b-a <5){
                for(int k=j+1; k< pList.size() ; k++){
                    int z;  z= pList[k];
                    double val;
                    if(z >= c/2.0){
                        val= z- c/2.0;
                    }
                    else{
                        val= z + c/2.0;
                    }

                    if(val> a && val< b){
                       // cout << a << " " << b << " " << z << endl;
                      //  cout << freq[a] << " " << freq[b]   << " " << freq[z] << endl;
                        count += freq[a]*freq[b]*freq[z];
                    }
                }
            }
            
        }
    }
    cout << count; 




}
