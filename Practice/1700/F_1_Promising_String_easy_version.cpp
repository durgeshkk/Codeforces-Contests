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
    string s;cin>>s;

    vector<ll> v(n+1,1);
    for(ll i = 1;i<=n;++i){
        if(s[i-1] == '-'){v[i] = -1;}
    }

    vector<ll> pref(n+1,0);
    for(ll i = 1;i<=n;++i){
        pref[i] = pref[i-1]+v[i];
    }

    ll ans = 0;
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            ll diff = pref[j]-pref[i-1];
            if(diff%3 == 0 and diff <= 0){++ans;}
        }
    }
    cout<<ans<<endl;

    
    // Something missing
    /*
    // First, store the no. of consecutive '-' in 2-D array!!
    // Then brute force the solution with start & end pointer to get the subsequence.
    // And to store no. of '+' and '-' use prefix pair array

    vector<vector<ll>> v(n+1,vector<ll> (n+1));
    for(ll i=0;i<n;i++){
        ll cnt = 0,mx = 0;
        for(ll j=i;j<n;j++){
            if(s[j] == '-'){++cnt;}
            else{cnt = 0;}
            mx = max(mx,cnt);
            v[i+1][j+1] = mx;
        }
    }

    vector<pair<ll,ll>> pref(n+1,{0,0});
    ll sub = 0,plus = 0;
    for(ll i=0;i<n;i++){
        if(s[i] == '-'){++sub;}
        else{++plus;}
        pref[i+1] = {sub,plus};
    }

    ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            // It's a substring from [i,j]
            auto pl = pref[i],pr = pref[j+1];
            ll cnt_sub = pr.first-pl.first;
            ll cnt_plus = pr.second-pl.second;

            // I got no. of '+' & '-' from [i,j]
            if(cnt_plus == cnt_sub){
                // cout<<i<<" "<<j<<endl;
                ++ans;
            }
            else if(cnt_sub > cnt_plus){
                // cout<<i<<" "<<j<<" ";
                ll z = (cnt_sub-cnt_plus)/3;
                if((cnt_sub-cnt_plus)%3){

                }else{
                    ll mx = v[i+1][j+1];
                    ll deliver_plus = mx/2;
                    if(deliver_plus >= z){
                        ll a = cnt_sub - 2*z;
                        ll b = cnt_plus + z;
                        // cout<<a<<" "<<b<<" ";
                        if(a == b){
                            ++ans;
                        }
                    }
                }
                // cout<<endl;
            }
        }
    }
    cout<<ans<<endl;*/
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