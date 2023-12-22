    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    int inf= 1e9;
    int N;

    unordered_set<int> primes;

    bool isP(int n){
        for(int i= 2; i <= sqrt(n); i++){
            if(n % i == 0) return false;
        }

        return true;
    }

    void f(int b){

        int n= b*2;

        for(int i=2; i<n; i++){
            if(primes.count(i) && primes.count(n-i)){
                cout <<  i << " "<< n-i << '\n';
                return;
            }
            else{
                if(isP(i) && isP(n-i)){
                    primes.insert(i); primes.insert(n-i);
                    cout <<  i << " "<< n-i << '\n';
                   return;
                }
            }
        }


    }


    int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);


        cin >> N;

        for(int i=0; i< N; i++){
            int b; cin >> b;
            f(b);
        }

    }