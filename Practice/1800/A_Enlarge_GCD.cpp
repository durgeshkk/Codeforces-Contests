/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#define ll int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

#define MAXN 15000007
 
// stores smallest prime factor for every number
ll spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (ll i = 2; i < MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (ll i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (ll i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (ll j = i * i; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
map<ll,ll> mp;    
vector<ll> ret;
void getFactorization(ll x,ll f)
{
    if(x == 1){return;}
    map<ll,ll> sa;
    while (x != 1) {
        if(f){
            sa[spf[x]]++;
        }else{
            ret.push_back(spf[x]);
        }
        x = x / spf[x];
    }

    // for(auto it:sa){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }cout<<endl;

    for(auto it:ret){sa[it]--;}
    for(auto it:sa){
        if(sa[it.first] > 0){
            mp[it.first]++;
        }
    }
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    sort(all(v));
    ll gcd = v[0];
    for(ll i=0;i<n;i++){
        gcd = __gcd(v[i],gcd);
    }

    if(gcd == 1 and v[n-1] == 1){
        cout<<"-1\n";return;
    }
    
    getFactorization(gcd,0);

    for(ll i=0;i<n;i++){
        getFactorization(v[i],1);
    }
 
    // cout<<gcd<<endl;return;
    
    ll ans = n;
    for(auto it:mp){
        // cout<<it.first<<" "<<it.second<<endl;
        ans = min(ans,n-it.second);
    }
    if(ans == n){
        ans = -1;
    }
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
   sieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
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