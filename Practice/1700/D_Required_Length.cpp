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
 
ll n; 
map<ll,ll> dp;
ll recur(ll x){
    string st = to_string(x);
    ll sz = st.size();
    if(sz == n){
        return 0ll;
    }

    if(dp.find(x) != dp.end()){
        return dp[x];
    }

    ll ans = 1e17;
    for(ll i = 0;i<st.size();++i){
        if(st[i] == '0' || st[i] == '1'){
            continue;
        }

        ll dig = (st[i]-'0');
        ll small_ans = recur(dig*x);//operations
        ans = min(ans,small_ans);
    }

    if(ans == 1e17){return ans;}
    return dp[x] = (1+ans);
}

// Faltu :
ll bfs(ll x){
    queue<ll> q;
    q.push(x);
    q.push(-1);//end of a lvl

    ll found = 0,ans = 0;
    while(!q.empty()){
        ll tp = q.front();
        q.pop();
        if(tp == -1){
            ++ans;
            continue;
        }

        string st = to_string(tp);
        for(ll i = 0;i<st.size();++i){
            ll val = tp*(st[i]-'0');
            q.push(val);
        }
        q.push(-1);

        if(st.size() == n){
            found = 1;break;
        }
    }

    if(found & 1){
        return ans;
    }else{
        return -1;
    }
}

void solve()
{
 
    ll x;cin>>n>>x;

    ll ans = recur(x);
    if(ans == 1e17){ans = -1;}
    // ll ans = bfs(x);
    cout<<ans<<endl;
    return;
    // Hamesha thinking of greater multiplication is always bad choice 
    // Always think recursively...
    /*
    ll prev = n,op = 0;
    while(1){
        string st = to_string(x);
        if(st.size() == n){break;}

        ll val = 0;
        for(ll i = 0;i<st.size();++i){
            char ch = st[i];
            ll bg = (ch-'0');
            ll z = x*bg;
            val = max(val,z);
        }
        // sort(st.begin(),st.end());
        x = val;
        ++op;
        cout<<x<<" "<<op<<endl;
        if(prev == x){cout<<"-1\n";return;}
        prev = x;
    }
    cout<<op<<endl;*/
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