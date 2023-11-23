#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 

 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
vector<ll> printDivisors(int n)
{
    vector<ll> x;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            if(n/i == i){
                x.push_back(i);
            }else{
                x.push_back(i);
                x.push_back(n/i);
            }
        }
    }
    return x;
} 

bool prime[1000001];
void SieveOfEratosthenes(ll n){
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (ll p = 2; p * p <= 1e6; p++) {
        if (prime[p] == true) {
            for (ll i = p*p; i <= 1e6; i += p)
                prime[i] = false;
        }
    }
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    sort(all(v));

    vector<ll> dp(n+1,0);
    vector<ll> freq(n+1,0);
    vector<ll> ok;
    forj(n){
        if(v[j] <= n){
            freq[v[j]]++;
        }
    }

    ll mx = 0;
    for(ll i = 1;i<=n;++i){
        for(ll j = i;j<=n;j+=i){
            dp[j] += freq[i];
            mx = max(mx,dp[j]);
        }
    }
    cout<<mx<<endl;

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