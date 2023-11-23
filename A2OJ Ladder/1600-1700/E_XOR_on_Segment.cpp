#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for (ll j = 0; j < 21; j++) cout<<a[j]<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
#define MAX_BIT 21

/*
// Pepcoding
https://www.youtube.com/watch?v=-0aHohlTotM
*/

class Pair{
public:
    ll sm = 0;
    ll cnt[MAX_BIT] = {0};
    Pair(){}
    Pair(ll s){
        sm = s;
        for(ll i = 0;i<MAX_BIT;++i){
            ll mask = 1<<i;
            if((s & mask) > 0){
                cnt[i] = 1;
            }
        }
    }
    Pair(Pair l,Pair r){
        sm = (l.sm+r.sm);
        for(ll i = 0;i<MAX_BIT;++i){
            cnt[i] = (l.cnt[i]+r.cnt[i]);
        }
    }
};

vector<Pair> tree;
vector<ll> lazy;

void buildTree(vector<ll> &arr,vector<Pair> &tree, ll start, ll end, ll treeNode) {
    // Base Case when start == end since we know the ans of that idx
    if(start == end){
        tree[treeNode] = Pair(arr[start]);
        return;
    }

    ll mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = Pair(tree[2*treeNode],tree[2*treeNode+1]);
}

void propogate(ll node,ll start,ll end){
    if(lazy[node] == 0){return;}

    if(start == end){
        ll val = ((tree[node].sm)^lazy[node]);
        tree[node] = Pair(val);
    }else{
        ll x = lazy[node];
        lazy[node*2] ^= x;
        lazy[node*2+1] ^= x;
        ll sum = (tree[node].sm);
        for(ll i = 0;i<MAX_BIT;++i){
            ll mask = 1<<i;
            if((x & mask) > 0){
                ll cnt_one = tree[node].cnt[i];
                ll cnt_zero = ((end-start+1)-cnt_one);
                ll diff = cnt_zero-cnt_one;
                // This bit contri {Inc or Dec}: by 2^i i.e. ntng bt mask 
                ll contri = (diff*mask);
                sum += contri;
                // This ppl's are gonna be 1  
                tree[node].cnt[i] = cnt_zero;
            }
        }
        tree[node].sm = sum;
    }
    lazy[node] = 0;
}

// Update O(log n)
void update(vector<ll> &arr,vector<Pair> &tree, ll start, ll end, ll treeNode, ll l,ll r, ll val) {
    propogate(treeNode,start,end);
    if(l > end || r<start){return;}
    if(start == end){
        lazy[treeNode] ^= val;
        propogate(treeNode,start,end);
    }
    else if(start >= l and end <= r){
        lazy[treeNode] ^= val;
        propogate(treeNode,start,end);
    }else{
        ll mid = (start+end)/2;
        update(arr,tree,start,mid,2*treeNode,l,r,val);
        update(arr,tree,mid+1,end,2*treeNode+1,l,r,val);
        tree[treeNode] = Pair(tree[2*treeNode],tree[2*treeNode+1]);
    }
}

ll query(vector<Pair> &tree, ll start,ll end, ll treeNode, ll left, ll right){
    propogate(treeNode,start,end);
    // 1.completely outside : return 0
    if(start > right || end < left){
        return 0;
    }

    if(start == end){
        return tree[treeNode].sm;
    }
    // 2.completely inside : return val
    if(start >= left and end <= right){
        return tree[treeNode].sm;
    }

    // 3.partially inside : call recursion on left & right
    ll mid = (start+end)/2;
    ll ans1 = query(tree,start,mid,2*treeNode,left,right);
    ll ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    return (ans1+ans2);
}


void solve(){
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    // ll v[n];for(ll i=0;i<n;i++){cin>>v[i];}
    // constructST(v,n);
    // tree.assign(4*n+1,{0,{0}});
    tree.assign(4*n+1,0);
    lazy.assign(4*n+1,0);
    buildTree(v,tree,0,n-1,1);

    ll q;cin>>q;
    for(ll i=0;i<q;i++){
        ll tttt;cin>>tttt;
        ll l,r;cin>>l>>r;
        --l,--r;

        if(tttt == 1){
            // Get Sum Query
            ll ans = query(tree,0,n-1,1,l,r);
            cout<<ans<<endl;
        }else{
            ll x;cin>>x;
            // Update Query
            update(v,tree,0,n-1,1,l,r,x);
            // updateRange(n,l,r,x);
        }
        // show(lazy);
    }
 
    return;
}
 
signed main()
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