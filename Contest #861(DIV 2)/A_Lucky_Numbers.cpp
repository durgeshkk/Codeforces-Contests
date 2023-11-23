#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
    // for(ll i = 0;i<1e4;++i){
    //     cout<<1<<" "<<1000000<<endl;
    // }
    // return;
    ll l,r;
    cin>>l>>r;
    ll ans = 0,num = l;
    for(ll i=l;i<=r;i++){
        string s = to_string(i);
        ll mn = INT_MAX,mx = INT_MIN;
        for(ll j = 0;j<s.size();++j){
            mn = min(mn,(s[j]-'0'));
            mx = max(mx,(s[j]-'0'));
        }

        ll diff = mx-mn;
        if(diff >= ans){
            ans = diff;
            num = i;
        }
        if(diff == 9){break;}
    }   
    cout<<num<<endl;
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