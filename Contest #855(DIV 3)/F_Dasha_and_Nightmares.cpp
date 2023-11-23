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
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n;cin>>n;
    map<vector<ll>,ll> odd,even;
    ll ans = 0;
    for(ll k=0;k<n;k++){
        string s;cin>>s;
        vector<ll> tmp(26,0);
        ll cntr = 0;
        forj(s.size()){
            tmp[s[j]-'a']++;
            if(tmp[s[j]-'a'] == 1){++cntr;}
        }

        if(cntr == 26){continue;}
        for(auto &it:tmp){
            if(it == 0){it = 0;}
            else if(it & 1){it = 1;}
            else{it = 2;}
        }

        show(tmp);

        vector<ll> ok(26,0);
        for(ll i = 0;i<26;++i){
            if(tmp[i] == 1){ok[i] = 2;}
            else if(tmp[i] == 2){ok[i] = 1;}
            else{
                // Make this idx as 0 & all other 0's as 1
                for(ll j = 0;j<26;++j){
                    if(i == j){ok[j] = 0;}
                    else if(tmp[j] == 1){ok[j] = 2;}
                    else if(tmp[j] == 2){ok[j] = 1;}
                    else{ok[j] = 1;}
                }
                
                // if(k == 3){
                    show(ok);
                // }
                if(s.size() & 1){
                    // search in even map
                    if(even.find(ok) != even.end()){
                        ans += (even[ok]);
                    }
                }else{
                    // search in odd map
                    if(odd.find(ok) != odd.end()){
                        ans += (odd[ok]);
                    }
                }
                ok[i] = 1;
            }
        }

        if(s.size() & 1){
            odd[tmp]++;
        }else{
            even[tmp]++;
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