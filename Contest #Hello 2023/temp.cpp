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
 
void solve()
{
 
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);enter(v);
 
    // multiset<ll> ms;
    multiset<pair<ll,ll>> mp,ms;
    ll suff = 0;
    for(ll i=0;i<k;i++){
        suff += v[i];
        ms.insert({v[i],i});
        // ms.insert(v[i]);
    }

    ll op = 0,pref = 0;

    for(ll i=0;i<k-1;i++){
        pref += v[i];
        if(mp.find({v[i],i}) != mp.end()){
            // Iska subs pehle hi krlo

        }else{
            suff -= v[i];
            ms.erase(ms.find({v[i],i}));
        }

        while(suff > 0){
            auto lst = *ms.rbegin();
            ms.erase(ms.find(lst));
            // ms.insert(-1*lst);
            mp.insert(lst);
            suff -= (2*lst.first);
            ++op; 
            // cout<<i<<endl;
        }
    }

    cout<<op<<endl;
    if(mp.find({v[k-1],k-1}) != mp.end()){
        // Iska subs pehle hi krlo
    }else{
        suff -= v[k-1];
    }
    
    cout<<suff<<endl;
    suff = -336833218;
    pref = suff;
    for(ll i = k;i<n;++i){
        pref += v[i];
        if(pref < 0){
            ++op;
            pref += (2*abs(v[i]));
        }
    }
    cout<<op<<endl;
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