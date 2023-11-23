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

void solve()
{
 
    ll n;
    cin>>n;

    ll x;
    cin>>x;

    vector<ll> v,ag;
    ll f = 0;
    for(ll i=0;i<n;i++){
        ll z;
        cin>>z;
        if(z == x){
            f = 1;
            continue;
        }
        v.push_back(z-x);
    }

    if(v.size() == 0){
        cout<<0<<endl;
        return;
    }

    ll sm = 0;
    for(ll i = 0;i<v.size();++i){
        sm += v[i];
    }

    if(sm == 0 || (f == 1)){
        cout<<1<<endl;
    }
    else{
        cout<<2<<endl;
    }
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