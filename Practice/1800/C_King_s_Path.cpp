/*
      Author : ME
*/
#include<bits/stdc++.h>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll x,y,xd,yd;
    cin>>x>>y>>xd>>yd;
    ll n;cin>>n;
    map<pair<ll,ll>,ll> s;
    for(ll i=0;i<n;i++){
        ll z,l,r;cin>>z>>l>>r;
        for(ll j = l;j<=r;++j){
            s[{z,j}]++;
        }
    }
 
    map<pair<ll,ll>,ll> vis;

    queue<pair<ll,ll>> q;
    q.push({x,y});
    vis[{x,y}] = 1;

    ll ans = 0;
    vector<pair<ll,ll>> v = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            auto p = q.front();q.pop();
            ll i = p.first,j = p.second;
            if(i == xd and j == yd){cout<<ans<<endl;return;}

            for(auto it:v){
                ll newx = i+it.first,newy = j+it.second;
                if(s[{newx,newy}] and !vis[{newx,newy}]){
                    q.push({newx,newy});
                    vis[{newx,newy}] = 1;
                }
            }
        }
        ++ans;
    }
    cout<<"-1\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
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