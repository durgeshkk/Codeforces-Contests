/*
      Author : ME
*/
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

void solve()
{
 
    ll n,k;cin>>n>>k;

    // Simply go with Brute Force & check if it is pssbl to get atleast 2 as cnt of
    // set for any no.
    // Use map for the cnt

    map<vector<ll>,ll> vmp,mp2;
    vector<vector<ll>> v(n,vector<ll> (k,0));
    for(ll i = 0;i<n;++i){
        vector<ll> tmp;
        forj(k){
            cin>>v[i][j];
            tmp.push_back(v[i][j]);
        }
        vmp[tmp] = i;
    }

    map<ll,ll> mp;
    vector<vector<vector<ll>>> tp;

    for(ll i = 0;i<n;++i){
        for(ll j = i+1;j<n;++j){
            // if set exists for i & j : mp[i]++;
            vector<ll> need;
            for(ll z = 0;z<k;++z){
                if(v[i][z] == v[j][z]){
                    need.push_back(v[i][z]);
                }else{
                    need.push_back(3-(v[i][z]+v[j][z]));
                }
            }

            // need is ready, now search it
            if(vmp.find(need) != vmp.end()){
                ll idx = vmp[need];
                if(idx > i and idx > j){
                    tp.push_back({v[i],v[j],need});
                    mp2[v[i]]++,mp2[v[j]]++,mp2[need]++;
                }
            }
        }
    }

    ll ans = 0,dynamo;
    for(auto it:tp){
        ll okay = 0;
        for(auto j:it){
            // j is req vector!!
            mp2[j]--;
            okay += (mp2[j]);
        }
        ans += okay;
    }
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   while (t--)
   {
       solve();
   }
   return 0;
}
