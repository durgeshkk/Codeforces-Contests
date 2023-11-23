/*
      Author : ME
*/
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

ll n,k;
vector<ll> v;
ll helper(){
    ll badda = v[n-1],chotta = v[0];
    ll z = (badda-chotta);
    ll ans = z;
    ll l = 0,h = z;
    // cout<<z<<endl;
    // return 0;

    // Check if this ans as i is pssbl, it's damn sure that ans will lie between 
    // [0,badda-chotta]..
    while(l <= h){
        // Now assume i is the ans!!
        ll i = (l+h)/2;
        ll mn_low = (chotta/k);
        ll mn_high = (chotta);
        ll flag = 0;

        for(ll mn = mn_low;mn<=mn_high;++mn){
        // while(mn_low <= mn_high){
            // ll mn = (mn_low+mn_high)/2;
            ll mx = mn+i;
            ll f = 1;//ans is pssbl

            for(ll j = 0;j<n;++j){
                // All values of v[i] & j must lie between [mn,mx]..
                if(v[j] < mn){f = 0;break;}
                ll x;
                ll counter = 0;
                for(ll cnt = 1;cnt<=k;++cnt){
                    x = (v[j]/cnt);
                    if(x >= mn and x <= mx){
                        counter = 1;break;
                    }
                }
                if(counter == 1){
                }else{
                    f = 0;break;
                }
            }

            if(f & 1){
                // Ans is pssbl
                flag = 1;
                break;
            }else{
            }
        }
        if(flag & 1){
            ans = i;
            h = i-1;
        }else{
            l = i+1;
        }
    }
    return ans;
}
 
void solve()
{
 
    cin>>n>>k;
    v.assign(n,0);enter(v);

    ll a = v[0],b = v[n-1];
    ll ans = LLONG_MAX;
    ans = helper();
    /*
    for(ll i=1;i<=k;i++){
        ll mn = a/i;
        for(ll j = 1;j<=k;++j){
            ll mx = b/j;
            ans = min(ans,max(mx-mn,0ll));
            // cout<<i<<" "<<j<<" "<<mn<<" "<<mx<<endl;
        }
    }
    */
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