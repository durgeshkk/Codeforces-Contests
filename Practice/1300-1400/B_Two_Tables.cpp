#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
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
 /*
    ll l,b;
    cin>>l>>b;
    // cout<<l<<" "<<b;

    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    // cout<<x1<<y1<<x2<<y2;

    ll x,y;
    cin>>x>>y;
    // cout<<x<<y<<endl;

    ll sx = l-(x2-x1);
    ll sy = b-(y2-y1);

    if(y > sy){
        if(x > sx){
            cout<< -1 <<endl;
            return;
        }
    }

    ll uparl = l-x2;
    ll uparb = b-y2;

    ll nicchel = x1-0;
    ll niccheb = y1-0;

    ll ansx = x - max(uparl,nicchel);
    ll ansy = y - max(uparb,niccheb);

    double val = sqrt(1.0*ansx*ansx + 1.0*ansy*ansy);
    cout<<val<<setprecision(7)<<endl;*/
    
    ll w,h,x1,x2,y1,y2,a,b,wd,hd;
    cin>>w>>h>>x1>>y1>>x2>>y2>>a>>b;
   
    ll r,rr;
    bool ch=true;
   
    vector<ll>vv,vv1;
    wd=max(x1,x2)-min(x1,x2);
    hd=max(y1,y2)-min(y1,y2);
   
    if(wd+a<=w||hd+b<=h){
        if(wd+a<=w){
            if(a>x1)
            r=a-x1;
            else
            r=0;

            vv.push_back(r);
            x2=w-x2;
            if(a>x2)
            r=a-x2;
            else
            r=0;

            vv.push_back(r);
        }
        if(hd+b<=h)
        {
            if(b>y1)
            rr=b-y1;
            else rr=0;
            vv1.push_back(rr);
            y2=h-y2;
            if(b>y2)
            rr=b-y2;
            else rr=0;
            vv1.push_back(rr);
        }
    }
    else{
        cout<<"-1\n";
        ch=false;
    }

    if(ch==true){
        sort(vv.begin(),vv.end());
        sort(vv1.begin(),vv1.end());
        if(vv.empty()==false&&vv1.empty()==false)
        cout<<min(vv[0],vv1[0])<<"\n";
        else if(vv.empty()==false&&vv1.empty()==true)
        cout<<vv[0]<<setprecision(7)<<"\n";
        else if(vv.empty()==true&&vv1.empty()==false)
        cout<<vv1[0]<<setprecision(7)<<"\n";
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   setprecision(20);// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}