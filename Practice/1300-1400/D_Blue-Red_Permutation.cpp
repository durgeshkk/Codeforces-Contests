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
 
void solve()
{
 
    ll n;
    cin>>n;

    ll cntb = 0,cntr=0;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    string s;
    cin>>s;

    vector<pair<char,ll>> pr(n);
    for(ll i=0;i<n;i++){
        char a = s[i];

        if(a == 'B'){
            cntb++;
        }
        else{
            cntr++;
        }

        ll b = v[i];

        pr[i] = make_pair(a,b);
    }

    sort(pr.begin(),pr.end());

    /*
    for(ll i=0;i<n;i++){
        cout<<pr[i].first<<" "<<pr[i].second<<endl;
    }
    cout<<endl;
    */

    // cout<<cntb<<" "<<cntr<<endl;
   for(ll i = 0;i<cntb;++i){
       if(pr[i].second < (i+1)){
           cout<<"NO\n";
           return;
       }
   }
   
   for(ll i = cntb;i<n;++i){
       if(pr[i].second > (i+1)){
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
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}