// Manhattan Subarray
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
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);

    // Non-Decreasing and Non-Increasing r the req ones.
    // Any subarray of min. length 5 is always Bad since it can be either Non-Inc. 
    // or Non-Dec.
    // Thus, we need to brute force only for ubarray of size 3 & 4!!
    // Subarray of len 1 + 2 r always ans & 
    // Subarray of len 5+  r never in the ans!!

    ll ans = (n+n-1);//len 1 + 2
    if(n == 1){cout<<n<<endl;return;}
    else if(n == 2){cout<<ans<<endl;return;}

    ll bad = 0;
    // Checking for length = 3
    for(ll i=1;i<n-1;++i){
        if((v[i] >= v[i-1]) and (v[i] <= v[i+1])){
            ++bad;
        }else if((v[i] <= v[i-1]) and (v[i] >= v[i+1])){
            ++bad;
        }
    }  

    ans += (n-2-bad);
    // cout<<bad<<" ";
    // cout<<ans<<endl;

    bad = 0;
    // Checking for length = 4
    for(ll i = 0;i<n-3;++i){

        // Subarray from i to i+3
        vector<ll> z(4);
        ll k = 0;
        for(ll j = i;j<(i+4);++j,++k){
            z[k] = v[j];
        }
        // show(z);
        for(ll j = 1;j<3;++j){
            // Increasing
            if((z[j] >= z[j-1]) and (z[j] <= z[j+1])){
                ++bad;break;
            }else if(j == 1 and (z[j] >= z[j-1]) and (z[j] <= z[j+2])){
                ++bad;break;
            }else if( j == 2 and (z[j] >= z[j-2]) and (z[j] <= z[j+1]) ){
                ++bad;break;
            }

            // Decreasing
            if((z[j] <= z[j-1]) and (z[j] >= z[j+1])){
                ++bad;break;
            }else if(j == 1 and (z[j] <= z[j-1]) and (z[j] >= z[j+2])){
                ++bad;break;
            }else if( j == 2 and (z[j] <= z[j-2]) and (z[j] >= z[j+1]) ){
                ++bad;break;
            }
        }
        // cout<<bad<<endl;
    }

    if(n >= 4){
        ans += (n-3-bad);
    }
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}