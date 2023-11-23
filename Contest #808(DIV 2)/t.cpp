#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);


void solve()
{
 
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    enter(v);

    string ans;
    ordered_set os(v.begin(),v.end());
    
    for(ll i=0;i<n;i++){
        os.erase(os.find(v[i]));
        if(q <= 0){
            ans += '0';
            continue;
        }
        if(v[i] <= q){
            // cout<<v[i]<<endl;
            ans += '1';
        }
        else{
            ll rem = 0;
            ll tot = n-i-1;
            ll lb = os.order_of_key(q+1);
            // cout<<v[i]<<" "<<lb<<endl;
            if(q + lb <= tot){
                ans += '0';
            }
            else{
                
                if(q <= 0){
                    ans += '0';
                }
                else{
                    q--;
                    ans += '1';    
                }
                // cout<<v[i]<<" "<<q<<endl;
                
            }
        }
        
    }
 
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
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}