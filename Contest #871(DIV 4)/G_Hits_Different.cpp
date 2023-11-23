/*
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
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

vector<vector<ll>> dp(2025,vector<ll> (2025,0));
void pre(){

    // for(ll i = 0;i<=2023;++i){
    //     forj(i+1){

    //     }
    // }
    dp[1] = 1,dp[2] = 5,dp[3] = 10;
    ll r = 3,c = 0;
    for(ll i = 4;i<=(1e6);++i){
        ++c;
        ll sq = mod_mul(i,i,mod);
        
        if(c == 1){
            ll x = (i-r+1);
            dp[i] = mod_add(dp[x],sq,mod);
        }else if(c == r){
            ll y = (i-r);
            dp[i] = y;
            dp[i] = mod_add(sq,dp[i],mod);
        }else{
            ll x = (i-r+1);
            ll y = (i-r);
            ll j=y;
            j = j-r+2;
            // if(i == 5){
            //     cout<<x<<" "<<y<<endl;
            // }
            dp[i] = mod_add(dp[x],sq,mod);
            dp[i] = mod_add(dp[y],dp[i],mod);
            dp[i] = mod_sub(dp[i],dp[j],mod);
        }

        if(c == r){
            c = 0,r++;
        }
    }
} 

void solve()
{
 
    ll n;cin>>n;
    cout<<dp[n]<<endl;

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   pre();
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
}*/