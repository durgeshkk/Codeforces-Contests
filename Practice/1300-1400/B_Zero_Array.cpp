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

    ll sm = 0;
    vector<ll> v(n);
    map<ll,ll> mp;

    for(ll i=0;i<n;i++){
       cin>>v[i];
       sm += v[i];
       mp[v[i]]++;
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll mx = *max_element(v.begin(),v.end());

    if(sm%2){
        cout<<"NO\n";
        return;
    }

    ll sum = 0;
    ll f = 0;
    for(ll i=0;i<n;i++){
        if((v[i] == mx) && (mp[v[i]] >= 2)){
                mp[v[i]]--;
                mp[v[i]]--;
                i++;
                if(i+1<n){
                    mx = v[i+1];
                    // cout<<mx<<endl;
                }
                else{
                    mx = 0;
                    // cout<<mx<<endl;
                    break;
                }
                continue;
        }

        if(f == 0){
            mx = v[i];
        }
        else{
            sum += v[i];
        }
        // break;
    }

    if(sum < mx){
        cout<<"NO\n";
        return;
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
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}