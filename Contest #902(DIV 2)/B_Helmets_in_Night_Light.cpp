/*
Once in a LifeTime,
Will never let you Down!!
*/
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

bool compa(pair<ll,ll> &a,pair<ll,ll> &b){
    if(a.first < b.first){
        return true;
    }else if(a.first == b.first){
        return a.second >= b.second;
    }else{
        return false;
    }
} 

ll a[100005];
ll b[100005];
void solve()
{
 
    ll n,k;cin>>n>>k;
    forj(n){cin>>a[j];}
    forj(n){cin>>b[j];}
 
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++){
        v.push_back({b[i],a[i]});
    }

    // sort(all(v));
    // ll pep = n-1,ans = k;
    // forj(n){
    //     ll ele = min(pep,v[j].second);
    //     pep -= ele;
    //     ans += min(v[j].first,k)*ele;
    // }

    if(n > 1){
        sort(all(v),compa);
    }
 
    ll ans = k,people = 1;
    for(ll i = 0;i<v.size();++i){
        if(people >= n){break;}
        if(v[i].first >= k){ans += (n-people)*k;break;}
        if((people+v[i].second) >= n){
            ans += (n-people)*v[i].first;
            people = n;
        }else{
            ans += (v[i].first*v[i].second);
            people += v[i].second;
        }
        if(people >= n){break;}
    }
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