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
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n,k,z;cin>>n>>k>>z;
    vector<ll> v(n);enter(v);
    ll sm = 0;vector<ll> ak;
    for(ll i=0;i<=k;i++){
        sm += v[i];
    }
 
    for(ll i = k;i>=0;i-=2){
        if(i == 0){break;}
        ak.push_back(v[i]+v[i-1]);
        if(ak.size() == 5){break;}
    }

    ll ans = sm;
    
    vector<ll> pre(v);
    for(ll i = 1;i<n;++i){
        pre[i] += pre[i-1];
    }

    ll jmp = k;sm = v[0];
    for(ll i = 1;i<n and jmp>0;++i){
        jmp--;
        sm += v[i];
 
        ll r = min(z, (jmp+jmp%2)/2);
        ll p = v[i-1]*r;
        p += v[i]*min(z,jmp/2);
 
        ll left = max(0ll,jmp-z*2);
        p += sm;
        p += pre[i + left] - pre[i];
        ans = max(ans, p);
        /*
        ll jmp = i,left = k-jmp;
        ll reversal = 0,extra = 0;
        ll prev = v[i]+v[i-1];

        // Traverse only till no. of left jumps
        for(ll j = 0;j<min(left/2,z);++j){
            if(ak[j]>prev){break;}
            else{
                extra += (prev-ak[j]);
                ++reversal;
            }
        }

        if((jmp + 2*reversal + 1) == k){
            // Check for left pssbls
            // cout<<i<<" ";
            if(reversal < z){
                extra += (max(v[i+1],v[i-1])-v[i+1]);
            }
        }
        ans = max(ans,sm+extra);*/
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