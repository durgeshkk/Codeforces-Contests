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
            ++s;
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