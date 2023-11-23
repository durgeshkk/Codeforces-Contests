#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n,m;
    cin>>n>>m;

    set<ll> s;
    ll arr[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
            s.insert(arr[i][j]);
        }
    }

    map<ll,vector<ll>> akrow;
    for(ll i=0;i<n;i++){
        map<ll,ll> mp;
        for(auto &it:s){
            mp[it] = 0;
        }

        for(ll j=0;j<m;j++){
            mp[arr[i][j]]++;
        }

        for(auto &it:mp){
            akrow[it.first].push_back(it.second);
        }
    }

    ll ans = 0;
    for(auto &it:akrow){
        // cout<<it.first<<" ";
        vector<ll> &vec = it.second;
        // show(vec);

        for(ll i = 0;i<vec.size();++i){
            ll val = vec[i];
            for(ll j=i+1;j<vec.size();j++){
                ll dis = (j-i);
                ans += (dis*vec[j]*val);
            }
            // cout<<ans<<endl;
        }
    }




    map<ll,vector<ll>> dkcol;
    for(ll i=0;i<m;i++){
        map<ll,ll> mp;
        for(auto &it:s){
            mp[it] = 0;
        }

        for(ll j=0;j<n;j++){
            mp[arr[j][i]]++;
        }

        for(auto &it:mp){
            dkcol[it.first].push_back(it.second);
        }
    }

    for(auto &it:dkcol){
        vector<ll> &vec = it.second;
        // cout<<it.first<<"-->";
        // show(vec);
        for(ll i = 0;i<vec.size();++i){
            ll val = vec[i];
            for(ll j=i+1;j<vec.size();j++){
                ll dis = (j-i);
                ans += (dis*vec[j]*val);
            }
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
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}