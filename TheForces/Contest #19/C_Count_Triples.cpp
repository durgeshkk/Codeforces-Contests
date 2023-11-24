#include<bits/stdc++.h>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
vector<ll> printDivisors(ll n)
{
    // Note that this loop runs till square root
    vector<ll> v;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0){
            if (n/i == i){
                v.push_back(i);
            }else{
                v.push_back(n/i);
                v.push_back(i);
            }
        }
    }
    return v;
}

void solve()
{
 
    ll n,m;cin>>n>>m;
    vector<ll> a(n);enter(a);
    vector<ll> b(n);enter(b);
    vector<ll> c(n);enter(c);
    sort(all(a));sort(all(b));sort(all(c));

    map<ll,vector<ll>> mp;
    vector<ll> tmp = printDivisors(m);
    mp[m] = tmp;
    for(auto it:tmp){
        vector<ll> x = printDivisors(it);
        mp[it] = x;
    }

    unordered_map<ll,ll> mpb,mpc;
    for(ll i=0;i<n;i++){
        mpb[b[i]]++;mpc[c[i]]++;
    }

    ll ans = 0;
    forj(n){
        if(m%a[j]){continue;}
        ll ele = (m/a[j]);
        vector<ll> v = mp[ele];
        for(auto x:v){
            ll y = ele/x;
            ll sa = mpb[y]*mpc[x];
            ans += sa;
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}