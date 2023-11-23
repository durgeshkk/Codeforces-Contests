/*
      Author : ME
*/
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

ll ans; 
void fool(vector<ll> &v1,vector<ll> &v2,vector<ll> &v3){
    for(ll i = 0;i<v2.size();++i){
        ll ele = v2[i];

        ll a = lower_bound(v3.begin(),v3.end(),ele)-v3.begin();
        if(a == v3.size()){--a;}
        a = v3[a];

        ll b = upper_bound(v1.begin(),v1.end(),ele)-v1.begin();
        if(b != 0){--b;}
        b = v1[b];

        ll smallans = (a-b)*(a-b) + (b-ele)*(b-ele) + (a-ele)*(a-ele);
        ans = min(ans,smallans);
    }
}

void solve()
{
 
    ll r,g,b;cin>>r>>g>>b;
    vector<ll> red(r);enter(red);
    vector<ll> green(g);enter(green);
    vector<ll> blue(b);enter(blue);
 
    sort(red.begin(),red.end());
    sort(green.begin(),green.end());
    sort(blue.begin(),blue.end());

    ans = LLONG_MAX;
    fool(red,green,blue);
    fool(red,blue,green);
    fool(green,red,blue);
    fool(green,blue,red);
    fool(blue,red,green);
    fool(blue,green,red);
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