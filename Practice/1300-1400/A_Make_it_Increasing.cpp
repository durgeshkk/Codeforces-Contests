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
void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    ll ans = 1e18;
    for(ll i = 0;i<n;++i){
        // ll mid = (n/2);
        // v[i] = 0;
        ll cnt = 0;
        ll prev = 0;
        ll sm = 0;

        for(ll j = i+1;j<n;++j){
            // prev += v[j]-(prev%v[j]);
            ll x = (prev/v[j])+1;
            cnt += x;
            prev = (v[j]*x);
            // cnt++;
            // sm += (prev/v[j]);
        }
        // cout<<cnt<<endl;

        prev = 0;
        for(ll j = i-1;j>=0;--j){
            // prev += v[j]-(prev%v[j]);
            // sm += (prev/v[j]);
            ll x = (abs(prev/v[j])+1);
            cnt += x;
            prev = -(v[j]*x);
        }
        // cout<<cnt<<endl;
        // ans = min(ans,sm);
        ans = min(ans,cnt);
    }
    cout<<ans<<endl;
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