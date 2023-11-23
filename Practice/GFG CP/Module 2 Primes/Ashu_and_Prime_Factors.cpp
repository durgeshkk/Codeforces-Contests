#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#define mx 1000001
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

ll arr[mx] = {0};

void createsievetocountMPF(){
    // map<ll,ll> mp;
    ll ntlen = 1000000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == 1){
            arr[i]++;//for num itself
            
            for(ll j = i*i;j<=ntlen;j+=i){
                if(sieve[j] == 1){
                    sieve[j] = 0;
                    arr[i]++;
                }
            }
        }
    }

    ll t;
    cin>>t;
    while (t--)
    {
       ll n;
       cin>>n;
        cout<< arr[n] << endl;
    }
    // return mp[m];
}
 
void solve()
{
 
    ll n;
    scanf("%ld",&n);
    // cin>>n;
    
    // ll ans = createsievetocountMPF(n);
    // printf("%ld\n",ans);
    // cout << createsievetocountMPF(n)<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
//    ll t=1;
//    cin >> t;
//    while (t--)
//    {
//        ll n;
//        cin>>n;
//     //    solve();
        createsievetocountMPF();
//    }
   //solve();
   return 0;
}