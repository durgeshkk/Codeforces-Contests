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
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    ll ans = 0;
    if(v[0] == (n-1) || v[n-1] == (n-1)){
        cout<<"YES\n";
        return;
    }

    ll z = n;
    ll s = 0,l=0;
    for(ll i=0;i<n;i++){
        
        if(v[i] <= (n-1)){
            if(v[i] == s){
                s = 0;
                continue;
            }
            i += v[i];
        }else{
            ++s;
        }

    }

    if(s == 0){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
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
// else{
        //     if(v[i] == s){
        //         s = 0;
        //         z -= (v[i]+1);
        //     }else{
        //         ++l;
        //     }
        
        //     if(v[i] == z){
        //         cout<<"YES\n";
        //         return;
        //     }
        // }
    