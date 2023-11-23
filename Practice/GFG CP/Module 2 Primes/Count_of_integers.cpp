#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#define ll long long int
using namespace std;
 
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
 
bool sieve[100000001];
void createsieve(){
    ll ntlen = 100000001;
    sieve[0] = false;
    sieve[1] = false;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = true;
    }
 
    for(ll i = 2;i*i<ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == true){
 
            for(ll j = i*i;j<ntlen;j+=i){
                 sieve[j] = false;
            }
        }
    }

    
}

void solve(){
    
       ll n;
        cin>>n;

        ll ans = 0;
        vector<ll> v(n);

        for(ll i=0;i<n;i++){
           cin>>v[i];
           if(sieve[v[i]] == true){
               ans++;
            }
        }

        cout << ans <<endl;
}
 /*
void solve()
{
 
    
    
    // createsieve();

    for(ll i=0;i<n;i++){
       cout<< v[i] <<" ";
       cout<< sieve[v[i]] <<" ";
    }
    cout<<endl;


    for(ll i=0;i<n;i++){
        if(isPrime(v[i])){
            ans++;
        }
    }
    //    
    
    cout << ans <<endl;
    return;
}
 */
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
    createsieve();
   ll t=1;
   cin >> t;
   while (t--)
   {
        solve();
   }
   return 0;
}