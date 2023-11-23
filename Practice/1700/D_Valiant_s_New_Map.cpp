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
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll n,m;
vector<vector<ll>> arr;
bool check(ll mid){
    // Only n*m is pssbl to go!!
    vector<vector<ll>> tmp(n+1,vector<ll> (m+1,0));
    vector<vector<ll>> a(n+1,vector<ll> (m+1,0));
    for(ll i = 0;i<n;++i){
        forj(m){
            a[i][j] = arr[i][j];
        }
    }

    for(ll i = 0;i<n;++i){
        forj(m){
            if(arr[i][j] >= mid){
                a[i][j] = 1;
                tmp[i+1][j+1] = (tmp[i][j+1] + tmp[i+1][j] - tmp[i][j] + a[i][j]);
            }
        }
    }

/*
    for(ll i = 0;i<=n;++i){
        for(ll j = 0;j<=m;++j){
            cout<<tmp[i][j]<< " ";
        }cout<<endl;
    }cout<<endl;*/
            
    for(ll i = mid;i<=n;++i){
        for(ll j = mid;j<=m;++j){
            ll sm = tmp[i][j] - tmp[i][j-mid] - tmp[i-mid][j] + tmp[i-mid][j-mid];
            if(sm >= mid*mid){
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>m;
    arr.assign(n,vector<ll> (m,0));
    for(ll i=0;i<n;i++){
        forj(m){
            cin>>arr[i][j];
        }
    }
    
    ll l = 0,r = min(n,m);
    ll ans = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        // cout<<mid<<"\n";
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
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

