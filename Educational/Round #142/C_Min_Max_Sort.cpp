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
 
/*
Obs : 
1. If 1 & n on proper position, then ans req is all misplaced ele
2. Else ans req is (n/2)
*/
ll ak;
ll longestSubsequence(vector<ll> &a, ll n){
    map<ll,ll> mp;

    ll dp[n];
    memset(dp, 0, sizeof(dp));
 
    ll maximum = LLONG_MIN,ele = -1;
 
    for(ll i = 0; i < n; i++) {
        if (mp.find(a[i] - 1) != mp.end()) {
            ll lastIndex = mp[a[i] - 1] - 1;
            dp[i] = 1 + dp[lastIndex];
        }
        else
            dp[i] = 1;
 
        mp[a[i]] = i + 1;
 
        
        if(maximum <= dp[i]){
            maximum = max(maximum, dp[i]);
            ele = a[i];
        }
    }
 
    return maximum;
}

vector<pair<ll,ll>> ls(vector<ll> &a, ll n){
    map<ll,ll> mp;
    vector<pair<ll,ll>> v;

    ll dp[n];
    memset(dp, 0, sizeof(dp));
 
    ll maximum = LLONG_MIN,ele = -1;
 
    for(ll i = 0; i < n; i++) {
        if (mp.find(a[i] - 1) != mp.end()) {
            ll lastIndex = mp[a[i] - 1] - 1;
            dp[i] = 1 + dp[lastIndex];
        }
        else
            dp[i] = 1;
 
        mp[a[i]] = i + 1;
 
        
        if(maximum == ak){
            maximum = max(maximum, dp[i]);
            ele = a[i];
            v.push_back({maximum,ele});
        }
    }
 
    return v;
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);enter(v);

    vector<ll> dp(n+1,0);
    set<ll> s;
    for(ll i = 0;i<n;++i){
        s.insert(v[i]);
        if(s.find(v[i]-1) != s.end()){
            dp[v[i]] = dp[v[i]-1]+1;
        }else{
            dp[v[i]] = 1;
        }
    }

    ll ans = LLONG_MAX;
    for(ll i = 1;i<=n;++i){
        ll s = i-dp[i]+1,e = i;
        ll ok = max(s-1,n-e);
        ans = min(ans,ok);
    }
    cout<<ans<<endl;return;



    /*
    ak = longestSubsequence(v,n);

    auto p = ls(v,v.size());
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());

    // for(ll i = 0;i<p.size();++i){
    //     cout<<p[i].first<<" "<<p[i].second<<endl;
    // }

    ll mxi = 0,ans = n-1;
    for(ll i = 0;i<p.size();++i){
        // if(p[i].first >= mxi){
            mxi = p[i].first;
            ll s = p[i].second - mxi + 1;
            ll e = p[i].second;
            ll ok = max(s-1,n-e);
            if(ok > ans){
                cout<<s<<" "<<e<<endl;
            }
            ans = min(ans,ok);
        // }else{
        //     break;
        // }
    }
    // cout<<"====\n";
    cout<<ans<<"\n";
    return;

    // ll flag = 0;
    // ll cnt = 1;

    // if(v[0] == 1 || v[n-1] == n){flag = 1;}
    // for(ll i=0;i<n;i++){
    //     if(v[i] == cnt){++cnt;}
    // }
    
    // ll op = 0;
    // if(flag & 1){
    //     op = (n-cnt+1);
    // }else{
    //     op = n/2;
    // }
    // cout<<op<<endl;
    return;*/
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