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

const int n = 1e7+5;
const int M = 1e7+5;
const int N = 1e7+5;
vector<int> dk(n,0);
vector<int> ans(n,1e8);
//  "A" : 65, "a" : 97  (-> |) (<- &(~))

void pre(){
    for(int i = 1;i<N;++i){
        for(int j=i;j<N;j+=i){
            dk[j] += i;
        }
        if(dk[i] < M){
            ans[dk[i]] = min(ans[dk[i]],i);
        }
    }
}  
 
void solve()
{
 
    ll l;cin>>l;
    if(ans[l] == 1e8){
        ans[l] = -1;
    }
    cout<<ans[l]<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   pre();
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