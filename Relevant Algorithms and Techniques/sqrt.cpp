#include <iostream>
using namespace std;
#include <unordered_map>

typedef long long ll;

double sqRoot(double x, double tolerance){
    double low=0, high= x;

    while(high - low > tolerance){ //once high and low 'intersects' at the we know we have got the right answer
        double mid= low+(high-low)/2.0;
        if(mid*mid < x){
            low= mid;
        }
        else{
            high= mid;
        }

    }

    cout << high << " " << low << '\n'; //high will always == low

    return low;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, string> d;
    cout << (d["bruh"] == "") << endl;

}