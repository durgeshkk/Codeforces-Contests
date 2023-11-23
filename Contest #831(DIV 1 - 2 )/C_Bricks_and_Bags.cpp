#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
    
    ll mn = *min_element(v.begin(),v.end());
    ll mx = *max_element(v.begin(),v.end());

    ll ans = 0;
    sort(v.begin(),v.end());
    for(ll i = 0;i<n-1;++i) {
        ll val = 2*v[i+1]-v[i]-mn;
        ans = max(val,ans);
    }

    for(ll i = 0;i<n-1;++i) {
        ll val = (v[i+1]+mx - 2*v[i]);
        ans = max(val,ans);
    }
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   ll tt=1;
   cin >> tt;
   while (tt--){
       solve();
   }
   //solve();
   return 0;
}