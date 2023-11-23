/*
      Author : ME
*/
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
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}

ll getMid(ll s, ll e){return s + (e - s) / 2;}

ll MaxUtil(ll* st, ll ss, ll se, ll l,ll r, ll node){
    if (l <= ss && r >= se)
        return st[node];
 
    if (se < l || ss > r)
        return -1;
    ll mid = getMid(ss, se);
    return max(MaxUtil(st, ss, mid, l, r,2 * node + 1),MaxUtil(st, mid + 1, se, l,r, 2 * node + 2));
}

ll getMax(ll* st, ll n, ll l, ll r)
{
    // Check for erroneous input values
    if (l < 0 || r > n - 1 || l > r)
    {
        // prllf("Invalid Input");
        return -1;
    }
 
    return MaxUtil(st, 0, n - 1, l, r, 0);
}

ll constructSTUtil(ll arr[], ll ss, ll se,ll* st, ll si){
    if (ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }
 
    ll mid = getMid(ss, se);
    st[si] = max(constructSTUtil(arr, ss, mid, st,si * 2 + 1),constructSTUtil(arr, mid + 1, se,st, si * 2 + 2));
    return st[si];
}

ll* constructST(ll arr[], ll n){
    ll x = (ll)(ceil(log2(n)));
    ll max_size = 2 * (ll)pow(2, x) - 1;
    ll* st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

/*
Obs : 
1. If between 2 haircuts, there is any big hair cut then we need +2 blades of it..
e.g. 8,1,3,1 -> 1-1 max is 3 & so we need 2 blades of 1!!
*/

void solve()
{

    map<ll,vector<ll>> mp;

    ll n;cin>>n;
    vector<ll> hairs(n);enter(hairs);
    ll need[n];
    ll f = 1;
    set<ll> s;
    for(ll i = 0;i<n;++i){
        cin>>need[i];s.insert(need[i]);
        if(need[i] > hairs[i]){f = 0;}
    }

    // show(hairs);show(need);return;

    //--------
    // Complete the blades task
    ll q;cin>>q;
    vector<ll> blade(q);enter(blade);
    map<ll,ll> blade_size;
    for(ll i=0;i<q;i++){blade_size[blade[i]]++;}
    // show(blade);return;
    //--------
    
    for(ll i=0;i<n;i++){
        if(need[i] > hairs[i]){f = 0;}
        if(need[i] == hairs[i]){continue;}
        mp[need[i]].push_back(i);
    }
 
    // Build segment tree from given array
    // 0 based Indexing
    ll* st = constructST(need, n);
    map<ll,ll> req;
    while(!s.empty()){
        ll ele = *s.rbegin();
        s.erase(s.find(ele));
        // Now Traverse mp for particular ele
        vector<ll> tmp = mp[ele];
        if(tmp.size() == 0){continue;}

        ll ak = 0,flag = 0;
        for(ll i = 0;i<tmp.size()-1;++i){
            ll l = tmp[i],r = tmp[i+1];
            ll mx = getMax(st, n, l, r);
            if(mx > ele){
                if(flag == 0){
                    ak += 2;
                }else{ak++;}
                flag = 1;
            }
        }

        if(ak == 0){ak = 1;}
        req[ele] = ak;
    }

    // cout<<f<<endl;
    for(auto it:req){
        if(blade_size.find(it.first) == blade_size.end()){
            f = 0;break;
        }else{
            ll dk = blade_size[it.first];
            if(dk < it.second){f = 0;break;}
        }
    }
    yno(f);
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