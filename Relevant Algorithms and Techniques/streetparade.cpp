#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
typedef tree<int,null_type,std::less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    indexed_set s;
    s.insert(7);
    s.insert(9);
    s.insert(2);
    s.insert(3);


    cout << s.order_of_key(2) << '\n';


}