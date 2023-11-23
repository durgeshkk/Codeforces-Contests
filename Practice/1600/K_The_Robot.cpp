#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    string s;
    cin >> s;
    ll n = s.size();
    ll x = 0;
    ll y = 0;
    vector<pair<ll, ll>> ans(n);
    for (ll i = 0; i < n; i++)
    {

        if (s[i] == 'L')
        {
            x--;
        }
        else if (s[i] == 'R')
        {
            x++;
        }
        else if (s[i] == 'U')
        {
            y++;
        }
        else
        {
            y--;
        }
        ans[i] = {x, y};
    }

    for (ll i = 0; i < n; i++){
        pair<ll,ll> p = ans[i];
        ll x = 0;
        ll y = 0;
        for (ll j = 0; j < n; j++){
            ll dx = x;
            ll dy = y;
            if (s[j] == 'L')
            {
                dx--;
            }
            else if (s[j] == 'R')
            {
                dx++;
            }
            else if (s[j] == 'U')
            {
                dy++;
            }
            else
            {
                dy--;
            }

            if (dx == p.first && dy == p.second)
            {
                continue;
            }
            else
            {
                x = dx;
                y = dy;
            }
        }

        if(x == 0 && y == 0){
            cout << p.first << " " << p.second << endl;
            return;
        }
    }
    cout << 0 << " " << 0 << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

/*#include<bits/stdc++.h>
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
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}
// Fxn call(for ((b/a)%mod)) :
// ll c = (b*power(a,mod-2(prime num in power of a),mod))%mod;
// Also for formula like nCr..
ll power(ll base,ll n,ll mod){
   ll ans = 1;
   while( n!= 0){
      if(n%2){
          n-=1;
          ans = (ans*base)%mod;
      }
      else{
          n /= 2;
          base = (base*base)%mod;
      }
   }
   return ans;
}
 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
ll sieve[1000005];
void createsieve(){
    ll ntlen = 1000000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == 1){
 
            for(ll j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
            }
        }
    }
}
 
 
ll fact[100005];
ll powfact[100005];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=100005;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
         powfact[i] = power(fact[i],mod-2,mod);
    }
}
 
ll nCr(ll n,ll r){
     ll at = powfact[r];
     ll at2 = powfact[n-r];
     return ((fact[n]*((at*at2)%mod))%mod);
}
 
vector<ll> adj[100004];
 
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({1,0});
 
    while(!q.empty()){
        auto it = q.front();
        q.pop();
 
        ll node = it.first;
        ll par = it.second;
 
        cout<<node<<" ";
 
        for(auto it:adj[node]){
            if(it != par){
                q.push({it,node});
            }
        }
    }
}
 
ll height;
ll subtree[100005];
ll lev[100005];
ll parent[200005];
 
void dfs(ll node, ll par, ll level=1){

    cout<<node<<" ";
    lev[node] = level;
    height = max(height,level);
 
    ll sm = 0;
 
    parent[node] = par;
    for(auto it:adj[node]){
        if(it != par){
            dfs(it,node,level+1);
            sm += subtree[it];
        }
    }
    subtree[node] = 1+sm;
}
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
void solve()
{
    ll dx = 0,dy = 0;
    string s;cin>>s;
    ll n=s.size();
    pair<ll,ll> ans = {0,0};
    ll l=0,r=0,u=0,d=0;

    for(ll i=0;i<n;i++){
        if(s[i] == 'R'){++dx;++r;}
        else if(s[i] == 'L'){--dx;++l;}
        else if(s[i] == 'U'){++dy;++u;}
        else{--dy;++d;}
    }

    // cout<<dx<<" "<<dy<<endl;
    if(dx == 0 and dy != 0){
        ll cnt = 0;
        if(dy > 0){
            
            if(d == 0){
                ll tdx=0,tdy=0;
                for(ll i= 0;i<n;++i){
                    if(s[i] == 'R'){++tdx;}
                    else if(s[i] == 'L'){--tdx;}
                    else if(s[i] == 'D'){++tdy;}
                    else if(s[i] == 'U'){
                        cout<<tdx<<" "<<tdy+1<<endl;
                        return;
                    }
                }
            }

            // u > d
            u=d;
            for(ll i = n-1;i>=0 and d!=0 and u!=0;--i){
                if(s[i] == 'U'){
                    --u;
                }else if(s[i] == 'D'){
                    --d;
                }
            }

            if(u == 0){
                cout<<0<<" "<<1<<endl;return;
            }

            ll tdx=0,tdy = 0;
            for(ll i = 0;i<n and u!=0;++i){
                if(s[i] == 'R'){++tdx;}
                else if(s[i] == 'L'){--tdx;}
                else if(s[i] == 'U'){--u;++tdy;}
                else{--tdy;}
            }

            cout<<(tdx)<<" "<<(tdy+1)<<endl;
        }else{

            if(u == 0){
                ll tdx=0,tdy=0;
                for(ll i= 0;i<n;++i){
                    if(s[i] == 'R'){++tdx;}
                    else if(s[i] == 'L'){--tdx;}
                    else if(s[i] == 'U'){++tdy;}
                    else if(s[i] == 'D'){
                        cout<<tdx<<" "<<tdy-1<<endl;
                        return;
                    }
                }
            }

            // u < d
            d = u;
            for(ll i = n-1;i>=0 and u!=0 and d!=0;--i){
                if(s[i] == 'U'){
                    --u;
                }else if(s[i] == 'D'){
                    --d;
                }
            }

            if(d == 0){
                cout<< 0<<" "<< -1<<endl;return;
            }

            ll tdx=0,tdy = 0;
            for(ll i = 0;i<n and d!=0;++i){
                if(s[i] == 'R'){++tdx;}
                else if(s[i] == 'L'){--tdx;}
                else if(s[i] == 'U'){++tdy;}
                else{--tdy;--d;}
            }

            cout<<(tdx)<<" "<<(tdy-1)<<endl;
        }
        return;
    }else if(dx != 0 and dy == 0){
        ll cnt = 0;
        if(dx > 0){

            if(l == 0){
                ll tdx=0,tdy=0;
                for(ll i= 0;i<n;++i){
                    if(s[i] == 'L'){--tdx;}
                    else if(s[i] == 'D'){--tdy;}
                    else if(s[i] == 'U'){++tdy;}
                    else if(s[i] == 'R'){
                        cout<<tdx+1<<" "<<tdy<<endl;
                        return;
                    }
                }
            }

            // r > l
            r=l;
            for(ll i = n-1;i>=0 and l!=0 and r!=0;--i){
                if(s[i] == 'L'){
                    --l;
                }else if(s[i] == 'R'){
                    --r;
                }
            }

            if(r == 0){
                cout<< 1<<" "<< 0<<endl;return;
            }

            ll tdx=0,tdy = 0;
            for(ll i = 0;i<n and r!=0;++i){
                if(s[i] == 'R'){--r;++tdx;}
                else if(s[i] == 'L'){--tdx;}
                else if(s[i] == 'U'){++tdy;}
                else{--tdy;}
            }

            cout<<(tdx+1)<<" "<<(tdy)<<endl;
        }else{

            if(r == 0){
                ll tdx=0,tdy=0;
                for(ll i= 0;i<n;++i){
                    if(s[i] == 'R'){++tdx;}
                    else if(s[i] == 'D'){--tdy;}
                    else if(s[i] == 'U'){++tdy;}
                    else if(s[i] == 'L'){
                        cout<<tdx-1<<" "<<tdy<<endl;
                        return;
                    }
                }
            }

            // r < l
            l=r;
            for(ll i = n-1;i>=0 and r!=0 and l!=0;--i){
                if(s[i] == 'L'){
                    --l;
                }else if(s[i] == 'R'){
                    --r;
                }
            }

            if(l == 0){
                cout<< -1<<" "<< 0<<endl;return;
            }

            ll tdx=0,tdy = 0;
            for(ll i = 0;i<n and l!=0;++i){
                if(s[i] == 'R'){++tdx;}
                else if(s[i] == 'L'){--l;--tdx;}
                else if(s[i] == 'U'){++tdy;}
                else{--tdy;}
            }
            cout<<(tdx-1)<<" "<<(tdy)<<endl;
        }
        return;
    }
    cout<<ans.first<<" "<<ans.second<<endl;
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
}*/