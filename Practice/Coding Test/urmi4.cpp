//CELEBRATING SEMIANNIVERSARY OF DADDY_DYNAMO!!
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;

void solve()
{
 
    string s;
    cin>>s;
    int n = s.size();

    string a,b;
    for(int i = 0;i<n;++i){
        if(i & 1){
            b += s[i];
        }else{
            a += s[i];
        }
    }

    reverse(b.begin(),b.end());
    a+=b;
    cout<<a<<endl;
    return;
}
 
int main()
{
   solve();
   return 0;
}