#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve(){
 
    ll n;cin>>n;

    vector<ll> v(n);
    enter(v);
 
    vector<ll> t(n);
    enter(t);

    vector<ll> z,o;
    for(ll i=0;i<n;i++){
        if(v[i] == 0){
            z.push_back(t[i]);
        }
        else{
            o.push_back(t[i]);
        }
    }

    sort(z.begin(),z.end());
    sort(o.begin(),o.end());

    ll ans = 0;
    for(auto it:t){
        ans += it;
    }
    ans *= 2;

    if(z.size() == o.size()){
        if(z[0] > o[0]){
            ans -= o[0];
        }else{
            ans -= z[0];
        }
    }else{
        if(z.size() > o.size()){
            ll diff = z.size()-o.size();
            for(ll i = 0;i<diff;++i){
                ans -= z[i];
            }
        }else{
            ll diff = (o.size()-z.size());
            for(ll i = 0;i<diff;++i){
                ans -= o[i];
            }
        }
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
   while (t--)
   {
       solve();
   }
   return 0;
}