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
 
    ll n,l;
    cin>>n>>l;
    vector<ll> v(n);enter(v);

    map<ll,ll> mp;
    mp[1] = 0,mp[2] = 0;
    for(auto it:v){
        mp[it]++;
    }
    // if(mp.size() == 1){cout<<"No\n";return;}

    for(ll i = n-1;i>0;--i){
        mp[v[i]]--;
        if(v[i] == 2){
            ll val = 3*mp[2]+2*mp[1];
            ll sp_rem = l-val;
            if(sp_rem<2){
                cout<<"No\n";return;
            }
        }
    }
    cout<<"Yes\n";return;


    ll f = 0;
    if(l & 1){
        if(is_sorted(v.begin(),v.end())){
            f = 1;
        }
    }else{
        reverse(v.begin(),v.end());
        if(is_sorted(v.begin(),v.end())){
            f = 1;
        }else{
            reverse(v.begin(),v.end());
            reverse(v.begin()+1,v.end());
            if(is_sorted(v.begin()+1,v.end()) and v[0] == 1){
                f = 1;
            }
        }
    }
    if(f & 1){cout<<"Yes\n";}
    else{cout<<"No\n";}    
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
//    cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}