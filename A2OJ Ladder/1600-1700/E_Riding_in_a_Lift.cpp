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
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int n,k,b; 
map<pair<int,int>,int> dp;

vector<vector<int>> mp;
int recur(int idx,int cnt){
    if(idx > n || idx < 1 || cnt > k){
        return 0;
    }

    if(cnt == k){
        return 1;
    }

    if(mp[idx][cnt] != -1){
        return mp[idx][cnt];
    }

    // if(dp.find({idx,cnt}) != dp.end()){
    //     return dp[{idx,cnt}];
    // }

    int dist = abs(b-idx);
    int x = 0, y = 0;
    for(int j = 1;j<dist;++j){
        int sa = recur(idx+j,cnt+1);
        x = mod_add(x,sa,mod);
        sa = recur(idx-j,cnt+1);
        y = mod_add(y,sa,mod);
    }

    return mp[idx][cnt] = mod_add(x,y,mod);
    // return dp[{idx,cnt}] = mod_add(x,y,mod);
}

void solve()
{
 
    int a;cin>>n>>a>>b>>k;
    mp.assign(n+1,vector<int> (n+1,-1));
    int ans = recur(a,0);
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}