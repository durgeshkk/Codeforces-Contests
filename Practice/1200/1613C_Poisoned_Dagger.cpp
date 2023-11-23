#include<bits/stdc++.h>
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
void solve()
{
 
    ll n,h;
    cin>>n>>h;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    // if(n == 1){
    //     cout<<(h-v[0])<<endl;
    //     return;
    // }
/*
    ll t = 0;

    for(ll i = 0;i<n-1;i++){
        ll sk = (n-i);
        ll gen = sk*(v[i+1]-v[i]);

        if(gen < h){
            h -= (v[i+1]-v[i]);
        }
        else{
            ll ans = ceil(1.0*h/sk);
            cout<<ans<<endl;
            return;
        }
    }

    if(h > 0){
        cout<<h<<endl;
    }*/

    ll l = 1, r = 1e18;
    while (l <= r) {
      ll m = (l + r) / 2;
      ll sum = m;
      for (int i = 0; i < n - 1; ++i) {
        sum += (min(m, v[i + 1] - v[i]));
      }
      
      if (sum < h){
          l = m + 1;
      } 
      else{
           r = m - 1;
      }
    }
    cout << r + 1 << '\n';
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}