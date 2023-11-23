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

map<pair<ll,ll>,ll> mp;
vector<ll> v;
string t = "hard";
ll recur(ll idx,string &s,ll j){
    if(j == t.size()){return LLONG_MAX;}
    if(idx == s.size()){return 0;}

    if(mp.find({idx,j}) != mp.end()){return mp[{idx,j}];}

    ll ans = LLONG_MAX;
    if(s[idx] == t[j]){
        // Remove this t[j],so add the cost of removal {a}
        ll a = v[idx] + recur(idx+1,s,j);
        // Keep this t[j] and proceed to remove from other remaining j's{b}
        ll b = recur(idx+1,s,j+1);
        ans = min(a,b);
    }else{
        ll a = recur(idx+1,s,j);
        ans = min(a,LLONG_MAX);
    }
    return mp[{idx,j}] = ans;
}
 
void solve()
{
    mp.clear();
    ll n;cin>>n;
    string s;cin>>s;
    v.assign(n,0);enter(v);
    // Memoization/Pure DP :
    // ll ans = recur(0,s,0);
    // cout<<ans<<endl;return;


    // Strong Logic :
    ll a=0,b = 0,c = 0,d = 0;
    for(ll i = 0;i<n;++i){
        if(s[i] == 'h'){
            a += v[i];
        }
        if(s[i] == 'a'){b = min(a,b+v[i]);}
        if(s[i] == 'r'){c = min(b,c+v[i]);}
        if(s[i] == 'd'){d = min(c,d+v[i]);}
    }
    cout<<d<<endl;return;
    // for(ll i=0;i<n;i++){mp[i] = v[i];}
 
    // First of all check which char's are involved in making/ resulting the 
    // subsequence as hard & then & then only we will try removing them!!
    // Then simply find cost of removing all useful h,a,r,d & return the min. of them
    
    
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