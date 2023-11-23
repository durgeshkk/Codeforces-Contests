/*
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
 
ll factorial(ll n)
{
    int res = 1, i;

    for (i = 2; i <= n; i++)
        res = (((res%mod)*(i%mod))%mod);
    
    return res;
}

void solve()
{
 
    ll n;
    cin>>n;

    ll x,pos;
    cin>>x>>pos;

    vector<vector<ll>> C(1001,vector<ll>(1001, 0));
    for(ll i=1;i<=1000;++i)C[0][i] = 0;
    for(ll i=0;i<=1000;++i)C[i][0] = 1;
    for(ll i=1;i<=1000;++i)
    {
        for(ll j=1;j<=i;++j)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }

    vector<ll> fact(1000, 0);
    fact[0] = 1;
    for(ll i=1;i<=1000;++i){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ll l=0,r=n;
    ll s=0,g=0;
    ll m = -1;

    while((l) < r){
        m = (l+r)/2;
        if(m <= pos){
            if(pos != m){
                ++s;
            }
            l = m+1;
        }
        else{
            // if(m > pos){
            ++g;
            r = m;
        }
        // else if(m == pos){
        //     l = m;
        //     break;
        // }
        // else{
            
        // }
        // cout<<"----\n";
        // cout<<l<<" "<<r<<endl;
        // cout<<s<<" "<<g<<endl;
        // cout<<"----\n";
    }

    ll gr8 = (n-x);
    ll ls = (x-1);
    --n;

    ll ans = (C[gr8][g] % mod * fact[g] % mod) % mod;
    ans = (ans * (C[ls][s] % mod * fact[s] % mod) % mod) % mod;
    ans = (ans * (fact[n-s-g])) % mod;

    // ll ans = ((C[gr8][g]*fact[g]) % mod * (C[ls][s] * fact[s]) % mod * (fact[n-s-g])) % mod;
    cout<<ans<<endl;

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
//    cin >> t;
   ll i = 1;
   while (t--)
   {
    //    cout<<"Case #"<<i<<": ";
       solve();
       ++i;
   }
   //solve();
   return 0;
}
*/
// /*
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
ll mod = (int)(1e9+7);
 
ll factorial(ll n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res = ((res%mod)*(i%mod)%mod);
    return res;
}

void solve()
{
 
    ll n;
    cin>>n;

    ll x,pos;
    cin>>x>>pos;

    ll l= 0,r = n;
    ll s=0,g=0;

    while(l < r){
        ll m = (l+r)/2;
        if(m < pos){
            // if(pos != m){
                ++s;
            // }
            l = m+1;
        }
        else if(m == pos){
            l = m+1;
        }
        else{
            // if(m > pos){
            ++g;
            r = m;
        }
    }

    ll gr8 = (n-x);
    ll ls = (x-1);

    ll ans1=1;
    for (int i = 0; i < g; i++)
        ans1 = (ans1 * (gr8 - i)) % mod;   
    
    ll ans2=1;
    for (int i = 0; i < s; i++)
        ans2 = (ans2 * (ls - i)) % mod;   

    --n;

    ll val5 = factorial(n-g-s)%mod;
    
    ll ans = (((ans1%mod)*(ans2%mod))%mod);
    ans = (((ans%mod)*(val5%mod))%mod);
    cout<<ans<<endl;
 
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
//    cin >> t;
   ll i = 1;
   while (t--)
   {
    //    cout<<"Case #"<<i<<": ";
       solve();
       ++i;
   }
   //solve();
   return 0;
}
// */