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
 
    ll n;
    cin>>n;

    ll j = 1;
    map<ll,ll> mp;

    multiset<pair<ll,ll>,greater<pair<ll,ll>>> ms;
    map<ll,set<ll>> ak;

    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;

        if(a == 1){
            ll b;cin>>b;
            ms.insert({b,j});
            mp[j] = b;
            ak[b].insert(j);
            ++j;
        }
        else if(a == 2){
            auto &it = *mp.begin();
            ll ff = it.first;
            ll ss = it.second;
            mp.erase(mp.begin());
            cout<<ff<<" ";
            pair<ll,ll> p = {ss,ff};
            ms.erase(p);

            set<ll> &st = ak[ss];
            st.erase(st.find(ff));

            // ak[ss] = st;
            if(st.empty()){
                ak.erase(ss);
            }
        }
        else{
            auto &val = *ak.rbegin();
            set<ll> &st = val.second;
            ll dk = val.first;

            ll idx = *st.begin();
            cout<<idx<<" ";
            st.erase(st.begin());
            ak[dk] = st;

            if(st.empty()){
                ak.erase(dk);
            }
            
            mp.erase(idx);
            pair<ll,ll> p = {dk,idx};
            ms.erase(ms.find(p));
        }

    }
    cout<<endl;
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