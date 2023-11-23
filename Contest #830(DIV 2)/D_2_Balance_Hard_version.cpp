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
    set<ll> s;
    map<ll,ll> mp;
    s.insert(0);

    set<ll> r;
    
    for(ll i=0;i<n;i++){
        char ch;cin>>ch;
        ll b;cin>>b;

        if(ch == '+'){
            s.insert(b);
        }
        else if(ch == '-'){
            for(auto &it:mp){
                // cout<<it.first<<" "<<2*it.first<<endl;
                if((it.first) > b){
                    break;
                }
                if((b % it.first) == 0){
                    it.second = min(it.second,b);
                }
            }
        }else{
            if(mp.find(b) == mp.end()){
                ll k = 0;
                while(s.find(k) != s.end()){
                    k += b;
                }
                cout<<k<<endl;
                mp[b] = k;
            }else{
                ll val = mp[b];
                if(s.find(val) == s.end()){
                    cout<<val<<endl;
                }else{
                    ll k = val;
                    while(s.find(k) != s.end()){
                        k += b;
                    }
                    cout<<k<<endl;
                    mp[b] = k;
                }
            }
        }
    }
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