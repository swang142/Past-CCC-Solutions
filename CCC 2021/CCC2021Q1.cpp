#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int inf= 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int N; cin >> N;

    vector<double> row (N+1), col(N);

    for(int i=0; i<= N; i++){
        cin >> row[i];
    }
    for(int i=0; i< N; i++){
        cin >> col[i];
    }

    double area= 0;

    for(int i=0; i< N; i++){
        double a= (row[i] + row[i+1])/2.0 * col[i];
        area+= a;
    }

    
    cout << fixed << setprecision(1) <<  area;

}
