#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first < b.first;

    return a.second < b.second;
}

int N; vector<int> sizes;
vector<pair<int, int>> v;



void solve(){
        for(int i= v.size()-1; i>0 ; i--){
            int curE= v[i].first; int curInd= v[i].second;
        
            if(v[i-1].first ==  curE){



                if( (i>1 && v[i-2].first == curE) && v[i-2].second +2 == v[i].second ){

                    if( (i>2 && v[i-3].first == curE) && v[i-3].second +3 == v[i].second ){
                        v[i-3].first*=4;
                        sizes[v[i-3].second]*=4;
                        sizes.erase(sizes.begin() + v[i].second);
                        v.erase(v.begin() + i);
                        i--;

                    }
                    else{
                        v[i-2].first*=3;
                        sizes[v[i-2].second]*=3;
                    }
                    

                    sizes.erase(sizes.begin() + v[i].second); sizes.erase(sizes.begin() + v[i].second -1);
                    v.erase(v.begin() + i); v.erase(v.begin() + i - 1);

                    for(int j=0; j< v.size(); j++){
                        if(v[j].second > curInd) v[j].second -= 2;
                    }
                    i--;
                }

                else if(v[i-1].second +2 == v[i].second ){
                    int xtra= sizes[v[i].second -1];

                    if((i>1 && v[i-2].first == curE) && (v[i-2].second+4 == v[i].second)&& (sizes[v[i-1].second-1] > xtra)){
                        xtra= sizes[v[i-1].second-1];
                        i--;
                    }

                    v[i-1].first*=2; v[i-1].first+= xtra;
                    sizes[v[i-1].second]*=2; sizes[v[i-1].second]+= xtra;

                    sizes.erase(sizes.begin() + v[i].second); sizes.erase(sizes.begin() + v[i].second -1);
                    v.erase(v.begin() + i);

                    for(int j=0; j< v.size(); j++){
                        if(v[j].first == xtra && v[j].second == v[i].second -1){
                            v.erase(v.begin()+ j);
                            j--;
                        }
                        else if(v[j].second > curInd) v[j].second -= 2;
                    }
                    i--;
                }
                else if(v[i-1].second +1 ==  v[i].second){

                    v[i-1].first *=2;
                    sizes[v[i-1].second]*=2;


                    sizes.erase(sizes.begin() + v[i].second);
                    v.erase(v.begin() + i);


                    for(int j= 0; j< v.size(); j++){
                        if(v[j].second > curInd) v[j].second -= 1;
                    }


                }
            }
    }
}

bool isFinished(){
    for(int i=0; i< sizes.size()-1; i++){
        if(sizes[i]== sizes[i+1]) return false;
        if(i < sizes.size()-2 && sizes[i]== sizes[i+2]) return false;
    }
    return true;
}

int main(){
    cin >> N;
    for(int i=0; i< N; i++){ int s; cin >> s; sizes.push_back(s); v.push_back({s, i}); }

    while(!isFinished()){
        sort(v.begin(), v.end(), comp);
        solve();
    }

    sort(sizes.begin(), sizes.end());
    cout << sizes[sizes.size()-1] << endl;





    





    


}