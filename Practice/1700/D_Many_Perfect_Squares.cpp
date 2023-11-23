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

ll check_sq(vector<ll> &v,ll x){
    ll n = v.size();
    ll ans1 = 0;
    for(ll i = 0;i<n;++i){
        double a = sqrt(v[i]+x);
        ll b = sqrt(v[i]+x);
        if(a == b){++ans1;}
    }
    return ans1;
}

/*
Obs :
1. Difference between v[i] will remain constant even after adding x...
2. Difference between squares is always odd increasing by diff. of 2 starting from
        1,4,9,16,25
         3,5,7, 9,...
3.  Ai + X = y2
    Aj + X = x2
    -----------
    (Aj-Ai)= x2-y2 = (x-y)(x+y) = p*q
    x = (p+q)/2,y = (p-q)/2

    X = x2-Aj;
*/

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);

    ll ans = 1;
    for(ll i = 0;i<n;++i){
        for(ll j = i+1;j<n;++j){
            ll diff = (v[j]-v[i]);
            for(ll x = 1;x*x<diff;++x){
                // Checking if diff%(sq) == 0
                if(diff%x == 0){
                    // Check if Parity is same !!
                    ll div = diff/x;
                    if((div+x)%2 == 0){
                        ll p = (div+x)/2;
                        ll q = (div-x)/2;

                        ll X = p*p-v[j];
                        // Now check if adding this add to all v can 
                        // make them perfect squares
                        if(X >= 0){
                            ll cnt = check_sq(v,X);
                            ans = max(ans,cnt);
                        }
                    }
                }
            }
        }
    }

    /*
    for(ll i = 0;i<n-1;++i){
        ll pssbl = 0;
        set<ll> s;
        ll mx_diff = 0;
        for(ll j = i+1;j<n;++j){
            s.insert(v[j]-v[i]);
            mx_diff = max(mx_diff,v[j]-v[i]);
        }

        ll ele = ceil(1.0*sqrt(v[i]+1));
        ele *= 2;++ele;
        cout<<ele<< " ";

        ll sm = 0;
        for(ll k = ele;sm<=mx_diff;k += 2){
            sm += k;
            if(s.find(sm) != s.end()){++pssbl;}
        }
        ans = max(ans,pssbl);
    }*/

    
    // ans = max(ans1,ans+1);
    cout<<(ans)<<endl;
    return;


    /*
    map<ll,ll> mp;
    // Check with diff. of 1,2 & so on till n-1


    for(ll i=1;i<n;i++){ //Diff. check

    }

    ll ele = ceil(1.0*sqrt(v[n-1]));
    for(ll j = ele;j*j<=1e18;++j){
        ll val = (j*j);
    }


    for(ll i=0;i<n;i++){
        // Find all perfect Squares pssbl for each v[i] till 1e18
        ll ele = sqrt(v[i]);
        for(ll j = ele;j*j<=1e18;++j){
            mp[(j*j)-v[i]]++;
        }   
    }
 
    ll ans = 0;
    for(auto it:mp){
        ans = max(it.second,ans);
    }
    cout<<ans<<endl;*/
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