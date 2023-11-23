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
    vector<ll> v(n),b(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }
    
    for(ll i=0;i<n;i++){
       cin>>b[i];
    }

    ll diff = v[0]-b[0];

    if(n == 1){
        if(b[0]>v[0]){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
        return;
    }

/*
    ll mx = -1;
    for(ll i=0;i<n;i++){
        ll ddf = b[i]-v[i];
        
        if(b[i] == 0){
            mx = max(mx,ddf);
        }
        else{

            if(mx > ddf){
                cout<<"NO\n";
                return;
            }
            mx = max(mx,ddf);
            break;
        }
    }

    if(b[0] == 0){

        ll mx = INT16_MIN;
        ll f=0;
        diff = v[0]-b[0];

        for(ll i=0;i<n;i++){

            if(b[i] != 0){
                ll dd = v[i]-b[i];

                if(dd < mx && (f ==0)){
                    cout<< "NO\n";
                    return;
                }
                else if(dd != mx && (f == 1)){
                    cout<< "NO\n";
                    return;
                }
                mx = max(mx,diff);
                f = 1;
            }
            else{
                mx = max(mx,diff);
            }
        }
        cout<<"YES\n";
        return;
    }


    diff = v[0]-b[0];
    ll f=0;

    for(ll i=0;i<n;i++){

        ll dd = v[i]-b[i];

        if(dd == diff){

        }
        else{
            if(b[i] == 0 && dd<diff){

            }
            else{
                cout<<"NO\n";
                return;
            }
        }
    }*/
    
    ll mx = INT16_MIN;
    for(ll i = 0;i<n;++i){
        ll d = v[i]-b[i];
        mx = max(mx,d);
    } 

    if(mx < 0){
        cout<<"NO\n";
        return;
    }
    // cout<<mx<<endl;

    for(ll i = 0;i<n;++i){

        ll d = v[i]-b[i];

        if(d < 0){
            cout<<"NO\n";
            return;
        }
        
        if(b[i] == 0){
            if(d<=mx){

            }
            else{
                cout<<"NO\n";
                return;
            }
        }
        else{
            if(d == mx){

            }
            else{
                cout<<"NO\n";
                return;
            }
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