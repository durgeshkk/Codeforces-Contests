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
    // for(ll i = 1;i<=200000;++i){
    //     cout<<200001<<" ";
    // }return;
    
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    ll ans = 0;
    ll prev = 0;
    for(ll i = 0;i<n;++i){
        while(prev != n){
            if(v[prev] >= (prev-i+1)){
                ++prev;
            }else{
                break;
            }
        }
        ans += (prev-i);
    }
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
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
//  *** This is not the subarray!!!
 /*
    ll prev = 0;
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        if(v[i] < (i+1-prev)){
            ll val = (cnt*(cnt-1)/2);
            ans += val;
            prev = i;
            cnt = 1;
        }else{
            ++cnt;
        }
    }

    if(cnt > 1){
        ll val = (cnt*(cnt-1)/2);
        ans += val;
    }
    */
