#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}
 
vector<ll> fib(46,1);

ll recur(ll n,ll x,ll y){
    if(n == 1){return 1;}
    ll curr_x = fib[n],curr_y = fib[n+1];
    y = min(y,curr_y-y+1);

    if(y > fib[n-1]){return 0;}
    return recur(n-1,y,x);
}

void solve()
{
 
    ll n,x,y;cin>>n>>x>>y;
    ll h = fib[n],w = fib[n+1];

    
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   for(ll i = 2;i<=45;++i){
        fib[i] = fib[i-1]+fib[i-2];
   }
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