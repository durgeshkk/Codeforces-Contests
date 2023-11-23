/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void myerase(ordered_set &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    
    vector<ll> pre(n);
    vector<ll> post(n);
    map<ll,ll> mp;
    ordered_set os; //use karte samay yaad rhe tree fxn remove karna h
    for(ll i=0;i<n;i++){
        mp[v[i]]++;
        pre[i] = mp[v[i]];
    }
    mp.clear();
    for(ll i = n-1;i>=0;--i){
        mp[v[i]]++;
        post[i] = mp[v[i]];
        os.insert(post[i]);
    }

    /*
    // We are given a ordered_set & we need to find cnt of element less than x
    // in it..

    // Steps :
    1. Find upper_bound of (x-1)
    2. Take the element & find it's idx in ordered_set
    3. Then add this idx to the ans
    */
    
    ll ans = 0;
    multiset<ll> ms(post.begin(),post.end());
    for(ll i=0;i<n-1;i++){
        ll ele = post[i];
        os.erase(os.find_by_order(os.order_of_key(ele)));
        ms.erase(ms.find(post[i]));

        // Now find upper_bound of pre[i]-1
        ll x = pre[i]-1;
        auto it = ms.upper_bound(x);
        if(it == ms.end()){
            ans += (ms.size());
        }else{
            ll z = *it;
            ll idx = os.order_of_key(z);
            ans += idx;
        }
    }
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