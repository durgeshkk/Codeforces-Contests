#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

vector<ll> h,beauty;
map<pair<ll,ll>,ll> mp;
vector<vector<ll>> dp;

// Brute Force : N2, keeping the ans of max. v[i] from prev...{TLE}

ll recur(ll idx, ll prev){
    if(idx == h.size()){
        return 0;
    }

    if(mp.find({idx,prev}) != mp.end()){return mp[{idx,prev}];}

    ll a = 0,b = 0;
    if(h[idx] > prev){
        // Update 0 to store 
        a = (recur(idx+1,h[idx]) + beauty[idx]);
    }
    b = recur(idx+1,prev);

    return mp[{idx,prev}] = max(a,b);
}
 
/*
Use state space optimised DP :
I do not need to store the ele picked before prev
We just need to store prev picked ele
dp[idx][prev] ==> It's is impssbl to optimise!!

This can be optimised using range query like 
     h->   2  5 3 8 7
e.g. b->   10 2 8 2 9

    So if height is h, then calculate max from (1,h[i]-1) and add b[i] to it..
    Like for h[0]=2 find max from (1,2-1) i.e. 0, mx = 0+10=10 and use update of 
    segment Query to store mx at h = 2;
    Then at h = 5 (1,5-1) => val = 10 so mx = 10+2=12 & ans = 12 & store mx at 
    h[1] or 5

So this will take an dp[n] to store mx!!
S.C.  =  O(n) & T.C. = O(n*log(n)) to update and find mx for given query
*/

void buildTree(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode) {
    // Base Case when start == end since we know the ans of that idx
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    ll mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = max(tree[2*treeNode] , tree[2*treeNode+1]);
}

// Update O(log n)
void update(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode, ll idx, ll val) {
    if(start == end){
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }

    ll mid = (start+end)/2;
    if(idx > mid){// move to right
        update(arr,tree,mid+1,end,2*treeNode+1,idx,val);
    }else{
        update(arr,tree,start,mid,2*treeNode,idx,val);
    }

    tree[treeNode] = max(tree[2*treeNode] , tree[2*treeNode+1]);
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

    return max(ans1,ans2);
}


void solve()
{
    mp.clear();
    ll n;cin>>n;
    h.assign(n,0);enter(h);
    beauty.assign(n,0);enter(beauty);

    vector<ll> dk(n+1,0);
    vector<ll> tree(4*n+4,0);
    buildTree(dk,tree,0,n,1);

    ll ans = 0;
    for(ll i = 0;i<n;++i){
        ll e = h[i];
        ll mx = query(tree,0,n,1,0,e-1);
        ans = max(ans,mx+beauty[i]);
        update(dk,tree,0,n,1,h[i],mx+beauty[i]);
    }

    // show(dk);
    // show(tree);
    cout<<ans<<endl;
    // Recur:
    // ll ans = recur(0,0);
    // cout<<ans<<endl;
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