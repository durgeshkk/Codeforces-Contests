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
    ll n,m,k;cin>>n>>m>>k;
    vector<ll> v(k);enter(v);

    set<ll> s;
    ll f = 0;
    ll val = k,space = n*m-(2);

    for(ll i=0;i<k;i++){
        s.insert(v[i]);

        if(s.size() >= space){
            f = 1;break;
        }

        while(s.find(val) != s.end()){
            s.erase(s.find(val));
            --val;
        }
    }
    
    if(f & 1){
        cout<<"TIDAK\n";
    }else{
        cout<<"YA\n";
    }
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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