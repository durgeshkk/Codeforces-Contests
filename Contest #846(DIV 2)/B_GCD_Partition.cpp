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

vector<ll> printDivisors(ll n){
    vector<ll> v;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0){
            if (n/i == i){
                v.push_back(i);
            }else{
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    return v;
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    
    ll sm = 0;
    vector<ll> pref(v);
    map<ll,ll> mp;
    for(ll i = 0;i<n;++i){
        sm += v[i];
        pref[i] = sm;
    }

    ll ans = 1;
    for(ll i = 0;i<n-1;++i){
        ll mx = __gcd(sm,pref[i]);
        ans = max(ans,mx);
    }
    cout<<ans<<endl;return;


    vector<ll> factors = printDivisors(sm);
    sort(factors.begin(),factors.end());
    
    for(ll i=0;i<factors.size()-1;i++){
        ll ele = factors[i];
        ll sum = 0,cnt = 0;

        for(ll j=0;j<pref.size()-1;j++){
            if(pref[j]%ele == 0){ans = ele;}
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