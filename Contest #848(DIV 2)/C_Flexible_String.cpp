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
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

/*
k is small : I can loop in k
a can have at most 10 different char;
So max pssbl = 10Ck & max value = 10!/(5!*5!) = 252 
*/

vector<ll> adj[100004];

void solve()
{
    for(ll i=0;i<26;i++){
        adj[i].clear();
    }

    ll n,k;cin>>n>>k;
    string a,b;cin>>a>>b;

    map<char,ll> mp;
    for(ll i=0;i<n;i++){
        mp[a[i]]++;
        adj[a[i]-'a'].push_back(i);
    }

    ll sz = mp.size();
    k = min(k,sz);
 
    // Selecting pair of size k
    // string st;for(auto it:s){st += it;}

    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll cnt = 0;
        map<char,ll> chottu;
        set<ll> dk;

        ll smallans = 0;
        for(ll j = i;j<n;++j){
            if(a[j] == b[j]){dk.insert(j);}
            else{
                if(cnt == k){break;}
                ++cnt;chottu[a[j]]++;
            }
        }

        for(auto it:chottu){
            for(auto x:adj[it.first-'a']){
                dk.insert(x);
            }
        }

        vector<ll> z(dk.begin(),dk.end());
        if(z.size() == 0){continue;}

        for(ll j = 0;j<z.size();++j){
            if((j<(z.size()-1)) and (z[j]+1 == z[j+1])){
                ll ak = 1;
                while((j<(z.size()-1)) and (z[j]+1 == z[j+1])){
                    ++ak;++j;
                }
                smallans += (ak*(ak+1)/2);
                if(j == (z.size()-1)){break;}
            }else{
                ++smallans;
            }
        }
        ans = max(ans,smallans);
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