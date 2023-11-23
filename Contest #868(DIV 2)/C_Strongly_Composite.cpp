#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

map<ll,ll> mp;
void primefactors(ll n)
{
    for (ll i = 2; i*i <= (n); i++) {
        while (n % i == 0) {
            n /= i;
            mp[i]++;
        }
    }
    mp[n]++;
}

void solve()
{
    mp.clear();
    ll n;cin>>n;
    vector<ll> v(n);enter(v);

    ll ans = 0;
    for(ll i=0;i<n;i++){
        primefactors(v[i]);
    }

    ll excess = 0;
    for(auto it:mp){
        if(it.first == 1){continue;}
        ll freq = it.second;
        // 2 factors pair to result 
        ans += (freq/2);
        // Rem adds
        excess += (freq%2);
    }
    ans += (excess/3);
    cout<<ans<<endl;
    return;
}
 
signed main()
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