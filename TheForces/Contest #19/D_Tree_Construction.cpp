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

vector<ll> leaves;
void constructTree(ll n, ll x, ll parent, ll depth) {
    if (n == 1 && x == 0) {
        leaves.push_back(parent);
        return;
    }

    if (x < 1 || x > n - 1 || depth == n - 1) {
        return;
    }

    ll minEdges = min(x, n - 2 - depth);
    for (ll i = 1; i <= minEdges; i++) {
        ll child = parent + i;
        leaves.push_back(child);
        constructTree(n, x - i, child, depth + 1);
    }
}

void solve()
{
 
    ll n,x;
    cin>>n>>x;
    ll mn = n-1,mx = (n/2)*((n+1)/2);
    // if(x < mn || x > mx){cout<<"-1\n";return;}
    vector<vector<ll>> tree = constructTree(n, x);
    if(!tree.empty()){
        for(ll i = 1;i<tree.size();++i){
            for(auto j:tree[i]){
                cout<<i<<" "<<j<<endl;
            }
        }
        return;
    }
    cout<<"-1\n";
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