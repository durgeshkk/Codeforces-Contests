#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll w,h,d;
    cin>>w>>d>>h;
    ll a,b,f,g;
    cin>>a>>b>>f>>g;
    ll ans1 = a+f+h+abs(b-g);
    ll ans2 = b+g+h+abs(a-f);
    ll ans3 = (w-a)+(w-f)+h+abs(b-g);
    ll ans4 = (d-b)+(d-g)+h+abs(a-f);
    
    ll ans = min({ans1,ans2,ans3,ans4});
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