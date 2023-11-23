#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> hand(n);enter(hand);
    vector<ll> pile(n);enter(pile);
 
    ll ans = 0;
    ll cntr = pile[n-1],j = n-1,f = 1,i = 0;
    while(j>=0){
        if(cntr == 0){break;}
        if(cntr != pile[j]){
            f = 0;break;
        }
        --j,--cntr;
    }

    multiset<ll> ms(all(hand));
    if(f){
        cntr = pile[n-1]+1;
        while(ms.find(cntr) != ms.end()){
            ms.insert(pile[i]);
            ++i;++cntr,++ans;
            if(cntr == n+1){break;}
        }
        if(cntr == n+1){
            cout<<ans<<endl;
            return;
        }
    }

    // n operations for Insertion is sure[1,n]
    ans = n;
    map<ll,ll> mp;

    ordered_set s;
    for(auto it:hand){
        if(!it){continue;}
        s.insert(it);
    }

    ll sa = 0;
    forj(n){
        ll ele = pile[j];
        if(ele == 0){continue;}
        s.insert(ele);
        ll x = s.order_of_key(ele);
        if(ele == x+1){
            sa = max(sa,j-ele+2);
        }else{
        }
    }
    ans += sa;
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