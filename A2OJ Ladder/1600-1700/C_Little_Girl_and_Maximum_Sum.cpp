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
 
void buildTree(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode) {
    // Base Case when start == end since we know the ans of that idx
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    ll mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

/*
Query : log(n)
*/
ll query(vector<ll> &tree, ll start,ll end, ll treeNode, ll left, ll right){

    // 1.completely outside : return 0
    if(start > right || end < left){
        return 0;
    }

    // 2.completely inside : return val
    if(start >= left and end <= right){
        return tree[treeNode];
    }

    // 3.partially inside : call recursion on left & right
    ll mid = (start+end)/2;
    ll ans1 = query(tree,start,mid,2*treeNode,left,right);
    ll ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);

    return ans1+ans2;
}

/*
Q : Prefix Sum + Segmented Trees
*/

void solve()
{
 
    ll n,q;cin>>n>>q;
    vector<ll> v(n);enter(v);
    vector<ll> pref(n+2,0);

    vector<pair<ll,ll>> qt;
    for(ll i=0;i<q;i++){
        ll a,b;cin>>a>>b;qt.push_back({a,b});
        pref[a]++;
        pref[b+1]--;
    }
 
    multiset<ll> tmp(v.begin(),v.end());
    multiset<pair<ll,ll>> ms;
    for(ll i = 1;i<=(n);++i){
        pref[i] += pref[i-1];
        ms.insert({pref[i],i});
    }

    // Smart Solution :
    /*
    sort(pref.begin(),pref.end());
    sort(v.begin(),v.end());
    ll j = pref.size()-1;
    ll ans = 0;
    for(ll i = n-1;i>=0;--j,--i){
        ans += (pref[j]*v[i]);
    }
    cout<<ans<<endl;
    return;*/

    // Segmented Tree : 
    vector<ll> arr(n+1,0);
    while(!ms.empty()){
        auto p = *ms.begin();ms.erase(ms.find(p));
        ll ele = *tmp.begin();tmp.erase(tmp.find(ele));
        arr[p.second-1] = ele;
    }
    arr.pop_back();
    // show(arr);

    vector<ll> tree(4*n+1);
    buildTree(arr,tree,0,arr.size()-1,1);
    ll sm = 0;
    for(ll i = 0;i<q;++i){
        ll l = qt[i].first,r = (qt[i].second);
        sm += (query(tree,0,arr.size()-1,1,l-1,r-1));
    }
    cout<<sm<<endl;
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