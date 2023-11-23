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
 
//  /*
set<ll> printDivisors(ll n)
{
    // Note that this loop runs till square root
    set<ll> s;
    for(ll i=1;i<=sqrt(n); i++){
        if(n%i == 0){
            // If divisors are equal, print only one
            if (n/i == i){
                s.insert(i);
            }else {
                s.insert(i);
                s.insert(n/i);
            }
        }
    }
    return s;
}
// */

/*
Obs:
1. Need to min. diff, So BS on diff & check if that diff can get the complete ans 
*/

map<ll,set<ll>> mp;
map<ll,ll> st;
map<ll,ll> dk;
/*
bool check(vector<ll> &v,ll mid){
    ll n = v.size();

    for(ll i = 0;i<n;++i){
        ll ele = (v[i]+mid);
    }
}*/

ll recur(set<ll> s,ll m){
    if(s.size() <= 1){
        return 1;
    }
    
    ll lst = *s.rbegin(),f = *s.begin();
    ll a = LLONG_MAX,b = LLONG_MAX;
    ll diff = (lst-f);

    // Try removing lst
    s.erase(s.find(lst));
    set<ll> tmp = mp[lst];
    for(auto it:tmp){
        dk[it]--;
        if(dk[it] == 0){
            dk.erase(dk.find(it));
        }
    }
    if(dk.size() == m){
        a = recur(s,m);
    }

    for(auto it:tmp){
        dk[it]++;
    }

    // Try removing frst
    s.insert(lst);
    s.erase(s.find(f));
    set<ll> tmp2 = mp[f];
    for(auto it:tmp2){
        dk[it]--;
        if(dk[it] == 0){
            dk.erase(dk.find(it));
        }
    }

    if(dk.size() == m){
        b = recur(s,m);
    }

    return min(a,b,diff);
}

void solve()
{
    st.clear();mp.clear();dk.clear();
 
    ll n,m;cin>>n>>m;
    set<ll> s,ass;
    vector<ll> v(n);enter(v);
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++){st[v[i]] = i;ass.insert(v[i]);}

    
    for(ll i=0;i<n;i++){
        set<ll> tmp = printDivisors(v[i]);
        for(auto it:tmp){
            mp[it].insert(v[i]);
            dk[it]++;
        }
    }

    
    for(ll i=1;i<=m;i++){s.insert(i);}

    ll ans= recur(ass,m);
    cout<<ans<<endl;
    return;
/*
    for(ll i=0;i<n;i++){
        set<ll> tmp = printDivisors(v[i]);
        for(auto it:tmp){
            mp[it].insert(v[i]);
        }
    }

    for(ll i=1;i<=m;i++){
        if(mp.find(i) == mp.end()){
            cout<<"-1\n";return;
        }
    }
 
    ll l = v[0],r = (v[n-1]-v[0]);
    ll ans = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(v,mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }*/
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