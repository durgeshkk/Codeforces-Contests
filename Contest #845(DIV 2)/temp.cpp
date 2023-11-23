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
 
map<ll,set<ll>> factors; 
void printDivisors(ll n)
{
    set<ll> s;
    for(ll i=1;i<=sqrt(n); i++){
        if(n%i == 0){
            if (n/i == i){
                s.insert(i);
            }else {
                s.insert(i);
                s.insert(n/i);
            }
        }
    }

    factors[n] = s;
    return;
}

ll diff;
ll recur(vector<ll> &v,ll idx,ll n,ll mn,ll mx,ll m,set<ll> s){
    if(idx == n){
        if(s.size() == m){
            diff = min(diff,mx-mn);
        }
        return;
    }

    
    for(auto it:factors[v[idx]]){

    }

    ll a = recur(v,idx+1,n,min(mn,v[idx]),max(mx,v[idx]),m,s);
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
 
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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