#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n;
    cin>>n;
    ll k;cin>>k;

    vector<ll> v(n);
    enter(v);
    vector<ll> ans(n);
 
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        mp[v[i]] = (i);
    }
    
    ordered_set s; //use karte samay yaad rhe tree fxn remove karna h
    for(ll i = 0;i<n;++i){
        s.insert(i);
    }

    ll f = 0;
    for(ll i = n;i>=1;--i){
        ll idx = mp[i];

        if(s.find(idx) == s.end()){
            continue;
        }

        ll a = s.order_of_key(idx);
        // cout<<a<<" ";
        
        ll remove = 0;
        // cout<<" --> ";
        while((a != (s.size()-1)) and (remove != k)){
            ll ak = *s.find_by_order(a+1);
            // cout<<ak<<" -- ";
            ans[ak] = f;
            s.erase(s.find(ak));
            ++remove;
        }

        remove = 0;
        while((a != (0)) and (remove != k)){
            ll ak = *s.find_by_order(a-1);
            ans[ak] = f;
            s.erase(s.find(ak));
            ++remove;
            --a;
        }
        ans[idx] = f; 
        s.erase(s.find(idx));
        f^=1;
        // cout<<endl;
    }

    for(ll i = 0;i<v.size();++i){
        cout<<ans[i]+1;
    }
    cout<<endl;
    // show(v);
    return;
}


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
//    cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}

 /*
    set<ll> s,idx;
    for(ll i = 1;i<=n;++i){
        s.insert(i);
        idx.insert(i-1);
    }

    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        mp[v[i]] = (i);
    }
 
    ll f = 0;
    vector<ll> ans(n,-1);
    vector<ll> vis(n,0);

    while(!s.empty()){
        ll val = *s.rbegin();
        s.erase(s.find(val));

        ll z = mp[val];

        if(!vis[z]){
            vis[z] = 1;
            ans[z] = f;

            ll cnt = 0;
            for(ll i = z+1;i<n;++i){
                if(cnt == k){
                    break;
                }
                
                if(!vis[i]){
                    s.erase(s.find(v[i]));
                    ++cnt,vis[i] = 1;
                    ans[i] = f;
                }
            }
            
            cnt = 0;
            for(ll i = z-1;i>=0;--i){
                if(cnt == k){
                    break;
                }

                if(!vis[i]){
                    s.erase(s.find(v[i]));
                    ++cnt,vis[i] = 1;
                    ans[i] = f;
                }
            }
        }else{
            continue;
        }

        f ^= 1;
    }
*/
/*
    while(!s.empty()){
        ll val = *s.rbegin();
        s.erase(s.find(val));

        ll z = mp[val];
        if(idx.find(z) == idx.end()){
            continue;
        }

        ll lb = mp[val]-k;
        ll ub = mp[val]+k;

        if(lb < 0){
            lb = 0;
        }

        if(ub > (n-1)){
            ub = (n-1);
        }

        for(ll i = lb;i<=ub;++i){
            if(idx.find(i) != idx.end()){
                idx.erase(idx.find(i));
                v[i] = f;
            }
        }
        f ^= 1;
    }
    */
