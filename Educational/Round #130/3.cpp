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
 
bool abtype(string s1,string s2,ll &i){
}

void solve()
{
 
    ll n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;

    if(s1 == s2){
        cout<<"YES\n";
        return;
    }

    if(n == 1){
        cout<<"NO\n";
        return;
    }

    if(n == 2){
        if(s1 == "ab" || s1 == "bc"){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return;
    }


    ll f = 0;
    ll cnta = 0,cntb=0,cntc=0;
    ll cnta2 = 0,cntb2=0,cntc2=0;
    ll idx = 0;
    for(ll i = 0;i<n;i++){

        if((s1[i] == s2[i]) && f == 0){
            continue;
        }

        if(s1[i] == 'a' && f == 0){
            idx = i;
            f = 1;
        }
        else if(s1[i] == 'b' && f == 0){
            if(f == 1){

            }
            else{
                idx = i;
                f = 2;
            }
        }

        if(f == 1){
            if(s1[i] == 'a'){
                cnta++;
                if(s2[i] == 'a'){
                    cnta2++;
                }
                else if(s2[i] == 'b'){
                    cntb2++;
                }
                else{
                    if(cntb2 == cntb && cnta2 == cnta){

                    }
                    else{
                        cout<<"NO\n";
                        return;
                    }
                    --i;
                }
            }

            else if(s1[i] == 'b'){
                cntb++;
                if(s2[i] == 'a'){
                    cnta2++;
                }
                else if(s2[i] == 'b'){
                    cntb2++;
                }
                else{
                    if(cntb2 == cntb && cnta2 == cnta){

                    }
                    else{
                        cout<<"NO\n";
                        return;
                    }
                    --i;
                }
            }

        }

        else if(f == 2){
            if(s1[i] == 'b'){
                cntb++;
                if(s2[i] == 'c'){
                    cntc2++;
                }
                else if(s2[i] == 'b'){
                    cntb2++;
                }
                else{
                    if(cntb2 == cntb && cntc2 == cntc){
                        cout<<cntb<<" "<<cntb2<<endl;
                        cout<<cntc<<" "<<cntc2<<endl;
                        cout<<endl;
                    }
                    else{
                        cout<<cntb<<" "<<cntb2<<endl;
                        cout<<cntc<<" "<<cntc2<<endl;
                        cout<<"NOi\n";
                        return;
                    }
                    --i;
                }
            }

            else if(s1[i] == 'c'){
                cntc++;
                if(s2[i] == 'c'){
                    cntc2++;
                }
                else if(s2[i] == 'b'){
                    cntb2++;
                }
                else{
                    if(cntb2 == cntb && cntc2 == cntc){
                        cout<<cntb<<" "<<cntb2<<endl;
                        cout<<cntc<<" "<<cntc2<<endl;
                        cout<<endl;
                    }
                    else{
                        cout<<"NO\n";
                        return;
                    }
                    --i;
                }
            }
        }
    }

/*
    for(ll i = 0;i<n;i++){
            if(s1[i] == 'a'){
                f = 1;
            }
            else if(s1[i] == 'b'){
                if(f == 1){

                }
                else{
                    f = 2;
                }
            }
            else if(s1[i] == 'c' && f == 0 && s2[i] != 'c'){
                cout<<"NO\n";
                return;
            }

            if(f == 1){
                if(s1[i] == 'a'){
                    cnta++;
                }
                else if(s1[i] == 'b'){
                    cntb++;
                }
                
                if(s2[i] == 'a'){
                    cnta2++;
                }
                else if(s2[i] == 'b'){
                    cntb2++;
                }


                if(s2[i] == 'c' || s1[i]=='c' || s2[i] == 'a' || s1[i]=='a'){
                    f = 0;

                    if(s1[i]=='b'){
                        cntb--;
                    }
                    else if(s1[i] == 'a'){
                        cnta--;
                    }
                    
                    if(s2[i]=='b'){
                        cntb2--;
                    }
                    else if(s2[i] == 'a'){
                        cnta2--;
                    }
                    --i;

                    if((cntb2 == cntb) && (cnta2 == cnta)){
                        cntb = 0;
                        cntb2 = 0;
                        cnta2 = 0;
                        cnta = 0;
                    }
                    else{
                        cout<<"NO\n";
                        return;
                    }
                }
            }
            else if(f == 2){
                if(s1[i] == 'b'){
                    cntb++;
                }
                else if(s1[i] == 'c'){
                    cntc++;
                }
                
                if(s2[i] == 'b'){
                    cntb2++;
                }
                else if(s2[i] == 'c'){
                    cntc2++;
                }
                
                if(s2[i] == 'a' || s1[i]=='a' || s2[i] == 'c' || s1[i]=='c'){
                    f = 0;
                    if(s1[i]=='b'){
                        cntb--;
                    }
                    else if(s1[i] == 'c'){
                        cntc--;
                    }
                    
                    if(s2[i]=='b'){
                        cntb2--;
                    }
                    else if(s2[i] == 'c'){
                        cntc2--;
                    }

                    --i;

                    if((cntb2 == cntb) && (cntc2 == cntc)){
                        cntc = 0;
                        cntb = 0;
                        cntb2 = 0;
                        cntc2 = 0;
                    }
                    else{
                        cout<<"NO\n";
                        return;
                    }
                }


            }
        // }
        
    }*/

    if(f == 1){

        if((cntb2 == cntb) && (cnta2 == cnta)){
            cntb = 0;
            cntb2 = 0;
            cnta2 = 0;
            cnta = 0;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    else if(f == 2){

        if((cntb2 == cntb) && (cntc2 == cntc)){
            cntc = 0;
            cntb = 0;
            cntb2 = 0;
            cntc2 = 0;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
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