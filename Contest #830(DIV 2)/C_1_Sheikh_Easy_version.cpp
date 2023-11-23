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
 

void buildtree(vector<ll> &arr, vector<pair<ll,ll>> &tree,ll s, ll e, ll treenode){

    // Base Case:
    if(s == e){
        tree[treenode] = {arr[s],arr[s]};
        return;
    }

    ll mid = (s+e)/2;
    buildtree(arr,tree,s,mid,2*treenode);
    buildtree(arr,tree,mid+1,e,2*treenode+1);

    ll sm = tree[2*treenode].first+tree[2*treenode+1].first;
    ll xr = tree[2*treenode]^tree[2*treenode+1];

    tree[treenode] = {(tree[2*treenode]+tree[2*treenode+1],tree[2*treenode]^tree[2*treenode+1])};
}

ll query(vector<ll> &tree,ll s, ll e,ll treenode, ll l, ll r){

    // If complete outside
    if(s > r || e < l){
        return LLONG_MAX;
    }

    // If completely in 
    if((s >= l) and (e <= r)){
        return tree[treenode];
    }

    // If partially in
    ll mid = (s+e)/2;
    ll ans1 = query(tree,s,mid,2*treenode,l,r);
    ll ans2 = query(tree,mid+1,e,2*treenode+1,l,r);
    return (ans1+ans2);
}




void solve()
{
 
    ll n;
    cin>>n;ll q;cin>>q;

    vector<ll> v(n);
    enter(v);
    ll l,r;cin>>l>>r;
    --l,--r;

    vector<ll> st;
    for(ll i=l;i<r;++i){
        st.push_back(v[i]+v[i+1]-(v[i]^v[i+1]));
    }
 
    pair<ll,pair<ll,ll>> p = maxSubArraySum(st,st.size());
    ll sm = p.first;
    if(sm == 0){
        
    }
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