#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
vector<ll> adj[100005];

void solve()
{
 
    ll n,m;cin>>n>>m;
 
    vector<ll> ans(n+1,0);
    for(ll i=0;i<m;i++){
        vector<ll> tmp(3);enter(tmp);
        sort(tmp.begin(),tmp.end());
        ll a = tmp[0],b = tmp[1],c = tmp[2];
        if(ans[a] == 0 and ans[b] == 0 and ans[c] == 0){
            ans[a] = 1,ans[b] = 2,ans[c] = 3;
        }
        else if(ans[a] != 0){
            // Cycle of 3
            ans[b] = (ans[a]%3)+1;
            ans[c] = (ans[b]%3)+1;
            /*
            if(ans[a] == 1){
                ans[b] = 2;ans[c] = 3;
            }
            if(ans[a] == 2){
                ans[b] = 1;ans[c] = 3;
            }
            if(ans[a] == 3){
                ans[b] = 1;ans[c] = 2;
            }*/
        }
        else if(ans[b] != 0){
            ans[c] = (ans[b]%3)+1;
            ans[a] = (ans[c]%3)+1;
            /*
            if(ans[b] == 1){
                ans[a] = 2;ans[c] = 3;
            }
            if(ans[b] == 2){
                ans[a] = 1;ans[c] = 3;
            }
            if(ans[b] == 3){
                ans[a] = 1;ans[c] = 2;
            }*/
        }
        else if(ans[c] != 0){
            ans[b] = (ans[c]%3)+1;
            ans[a] = (ans[b]%3)+1;
            /*
            if(ans[c] == 1){
                ans[b] = 2;ans[a] = 3;
            }
            if(ans[c] == 2){
                ans[b] = 1;ans[a] = 3;
            }
            if(ans[c] == 3){
                ans[b] = 1;ans[a] = 2;
            }*/
        }
    }

    for(ll i = 1;i<=n;++i){
        cout<<ans[i]<<" ";
    }cout<<endl;
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