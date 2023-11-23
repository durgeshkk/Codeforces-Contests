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

//  "A" : 65, "a" : 97  (-> |) (<- &(~))
ll mul2(ll x){
	return min(LLONG_MAX, 2*x);
}

ll power[100005];
void pre(){
    power[0] = 1;
    for(ll i = 1;i<=100005;++i){
        power[i] = mul2(power[i-1]);
    }
} 

void solve()
{
 
    ll n,k;cin>>n>>k;
    if(k > power[n-1]){
        cout<<"-1\n";return;
    }

    vector<ll> v(n+1,0);iota(all(v), 0);

    ll i = 1;
    while(i <= n){
        for(ll j = i;j<=n;++j){
            ll ele = j == n ? 1 : power[n-1-j];
            if(ele >= k){
                reverse(v.begin()+i,v.begin()+j+1);
                i = j+1;
                break;
            }else{
                k -= ele;
            }
        }
    }

    for(ll i = 1;i<=n;++i){
        cout<<v[i]<<" ";
    }cout<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   pre();
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