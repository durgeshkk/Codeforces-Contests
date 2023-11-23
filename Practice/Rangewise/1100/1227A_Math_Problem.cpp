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
 
void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> a(n),b(n);
    // ll a,b;
    // ll mn = INT16_MIN,mx = INT16_MAX;
    for(ll i=0;i<n;i++){
       cin>>a[i]>>b[i];
/*
        if(a > mn){
            mn = a;
        }

        if(b < mx){
            mx = b;
        }

        if(mn > mx){
            swap(mn,mx);
        }*/
    }

    ll lmax,rmin;
    lmax = *max_element(a.begin(),a.end());
    rmin = *min_element(b.begin(),b.end());

    if(n == 1){
        cout<<0<<endl;
        return;
    }

    ll ans = max(0LL,lmax-rmin);
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}