#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
map<vector<ll>,ll> mp;

// 3 D DP {2e5*2e5*632 ==> 2e14}
ll recur(ll r_remain,ll g_remain,ll lvl,ll h){
    if(lvl > h){return 1;}

    if(mp.find({r_remain,g_remain,lvl}) != mp.end()){
        return mp[{r_remain,g_remain,lvl}];
    }

    ll a = 0,b = 0;
    if(r_remain >= lvl){
        a = recur(r_remain-lvl,g_remain,lvl+1,h);
    }

    if(g_remain >= lvl){
        b = recur(r_remain,g_remain-lvl,lvl+1,h);
    }

    return mp[{r_remain,g_remain,lvl}] = mod_add(a,b,mod);
}
 
/*
At max. 632 lvls pssbl, So we can use 2-D dp of 2e5*632 = 1e8
This can be optimised by initially filling all the blocks from lvl = h using color 
green and then after when green comes to exhaust assume we r at lvl = 5 & g_remain = 3
So we fill the lvl 3 by g & then all other pending lvl's by red!!

Memo:
So we need to remember the lvl we are at which to color!!
Also we need red & green blocks pending...
{r_remain,g_remain,lvl} ==> TLE {2e14}

This can be optimised using : Not to store the g blocks as we have, r+g = k
From r_remain we will get {r_used => r_tot - r_remain}

r_used + g_used = fxn(lvl) & so by this we can get g_used
So this is optimised to r_remain*lvl = 1e8, but this will give MLE
1.4e8 bytes -> MB = (1.4e8*32/8/1024){KB}/1024 = 530 MB


*/

void solve()
{
    mp.clear();
    ll r,g;cin>>r>>g;

    // h is max height pssbl
    ll h = (sqrt(1.0*(1+(8*(r+g)))));
    h -= 1;h /= 2;

    // Now need to recur for this h
    ll ans = recur(r,g,1,h);
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