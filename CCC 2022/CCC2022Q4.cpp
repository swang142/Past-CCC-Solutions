#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int inf= 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n,c; cin >> n >> c;
    vector<int> freq(c+1, 0);
    vector<int> pList;
    
    for(int i=0; i< n; i++){
        int p; cin >> p;
        freq[p]++;   if(freq[p]==1) pList.push_back(p);
    }

    sort(pList.begin(), pList.end());

    int count=0;

      for(int i=0; i< pList.size() ; i++ ){
        for(int j=i+1; j< pList.size(); j++){
            for(int k=j+1; k< pList.size() ; k++){
                    int a, b, z; a= pList[i]; b= pList[j]; z= pList[k];
                    if(b-a < (c/2.0) && a+c-z < (c/2.0) && z-b < (c/2.0)){
                        double val;
                        if(z >= (c/2.0)){
                            val= z- (c/2.0);
                        }   
                        else{
                            val= z + (c/2.0);
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
