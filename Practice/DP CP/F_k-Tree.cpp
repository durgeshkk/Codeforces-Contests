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
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll d,k;
map<pair<ll,ll>,ll> mp;

ll recur(ll n,ll flag){
    
    if(n == 0){// Valid Path
        return flag;
    }

    if(n < 0){// InValid Path
        return 0;
    }

    if(mp.find({n,flag}) != mp.end()){return mp[{n,flag}];}

    ll ans = 0;
    for(ll i = 1;i<=k;++i){
        if(i >= d){
            ll ele = recur(n-i,1);
            ans = mod_add(ans,ele,mod); 
        }else{
            ll ele = recur(n-i,flag);
            ans = mod_add(ans,ele,mod); 
        }
    }

    return mp[{n,flag}] = ans;
}

void solve()
{
 
    ll sm;
    cin>>sm>>k>>d;
    
    ll ans = recur(sm,0);
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}