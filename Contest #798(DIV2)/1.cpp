#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
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
 
    ll n,m,k;
    cin>>n>>m>>k;

    string s1;
    cin>>s1;
    
    string s2;
    cin>>s2;

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
/*
    vector<pair<char,ll>> v,v2;
// /*
    // string s3 = s1+s2;
    for(ll i = 0;i<n;++i){
        v.push_back({s1[i],1});
    }

    for(ll i = 0;i<m;++i){
        v.push_back({s2[i],2});
    }

    ll cnta = 0,cntb = 0;    
    // ll mn = min(s1.size(),s2.size());
    // string s;
    // sort(s1.begin(),s1.end());
    // sort(s2.begin(),s2.end());
    sort(v.begin(),v.end());

    string ans;
    ll ta = 0,tb=0,t = 0;
    for(ll i = 0;i<v.size();++i){

        if(t<k){
            ans.push_back(v[i].first);

            if(v[i].second == 1){
                ta++;
                tb = 0;
                cnta++;

                if(ta == k){
                    while(v[i].second != 2){
                        v2.push_back(v[i]);
                        ++i;
                    }
                }
            }
            else{
                tb++;
                ta = 0;
                cntb++;
            }
        }

        if(ta == k){
            ta = 0;
            while(v[i].second != 2){
                v2.push_back(v[i]);
                ++i;
            }
        }

    }
*/
/*
    ll j = 0;
    ll ti = 0,tj=0;

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    cout<<s1<<" "<<s2<<endl;

    string s;
    // for(ll i = 0;(i<n)&&(j<m);){
    ll i = 0;
    ll f1=0,f2=0;

    while(1){

        while((s1[i]-'a')<(s2[j]-'a')){
            // cout<<"HI\n";
            if((i>=n)||(j>=m)){
                cout<<s<<endl;
                return;
            }

            s.push_back(s1[i]);
            ++i;
            ++ti;
            if(ti == k){
                if((i>=n)||(j>=m)){
                    cout<<s<<endl;
                    return;
                }
                s.push_back(s2[j]);
                ++j;
                ti = 0;
                tj = 0;
                break;
            }
        }

        cout<<s<<endl;
        
        
        while((s1[i]-'a')>(s2[j]-'a')){
            if((i>=n)||(j>=m)){
                cout<<s<<endl;
                return;
            }
            s.push_back(s2[j]);
            ++j;
            ++tj;

            if(tj == k){
                if((i>=n)||(j>=m)){
                    cout<<s<<endl;
                    return;
                }
                s.push_back(s1[i]);
                ++i;
                tj = 0;
                ti = 0;
                break;
            }
        }
        cout<<s<<endl;
    }

    cout<<s<<endl;*/
    
    ll i = 0,j=0,f=0;
    ll cnta=0,cntb=0;
    ll ta=0,tb=0;
    string ans;

    while(1){
        if(s1[i]<s2[j]){
            if(f == 0){
                ans.push_back(s1[i]);
                ++i;
                ta++;
                cnta++;
                tb = 0;
            }
            else{
                ans.push_back(s2[j]);
                ++j;
                ++tb;
                ta = 0;
                cntb++;
                f = 0;
            }
        }
        
        else{
            if(f == 0){
                ans.push_back(s2[j]);
                ++j;
                tb++;
                cntb++;
                ta = 0;
                // f = 1;
            }
            else{
                ans.push_back(s1[i]);
                ++i;
                ++ta;
                cnta++;
                tb = 0;
                f = 0;
            }
        }


        if(tb == (k)){
            f = 0;
        }

        if(ta == (k)){
            f = 1;
        }

        if(i>=n || j>=n){
            cout<< ans << endl;
            return;
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
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