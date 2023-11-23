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
ll mod = (ll)(1e9+7);

 
void solve()
{
 
    ll n,k;cin>>n>>k;
    vector<ll> health(n,0);
    for(ll i=0;i<n;i++){
        cin>>health[i];
    }

    vector<ll> power(n,0);
    for(ll i=0;i<n;i++){
        cin>>power[i];
    }
    
    map<ll,ll> mp;//need, mx_ele
    for(ll i=0;i<n;i++){
        if(mp.find(power[i]) == mp.end()){
            mp[power[i]] = health[i];
        }else{
            mp[power[i]] = max(health[i],mp[power[i]]);
        }
    }
 
    sort(health.begin(),health.end());
    multiset<pair<ll,ll>> multis;
    for(auto it:mp){
        multis.insert({it.first,it.second});
    }

    ll flag= 1,curr_k = k;
    for(ll i=0;i<n;){
        if(k > 0){}
        else{
            cout<<"NO\n";return;
        }

        while((health[i] <= curr_k)){
            ++i;
            if(i == n){break;}
        }
        if(i >= n){break;}
        
        ll need = 0;
        while(!multis.empty()){
            auto pt = *multis.begin();
            if(pt.second <= curr_k){
                multis.erase(multis.find(pt));
            }else{
                need = pt.first;
                break;
            }
        }
        curr_k += (k-need);
        k -= need;
    }

    cout<<"YES\n";
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