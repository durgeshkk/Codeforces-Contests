#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n,k;
    cin>>n>>k;

    vector<ll> ans(n,-1000);
    ll sm = 0;
    for(ll i=0;i<n;i++){
        sm += (i+1);
        ans[i] = 2;
        if(sm > k){
            ll diff = (sm-k);
            ans[i] = -1*(2*diff-1);
            break;
        }else if(sm == k){break;}
    }
    show(ans);
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