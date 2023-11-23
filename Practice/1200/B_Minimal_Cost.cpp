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
 
    ll n,u,v;
    cin>>n>>u>>v;

    vector<ll> a(n);
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
       cin>>a[i];
       mp[a[i]]++;
    }

    ll diff = INT16_MIN;
    for(ll i=0;i<n-1;i++){
        ll d = abs(a[i+1]-a[i]);

        if(d > diff){
            diff = d;
        }
    }

    ll ans =0;
    if(mp.size() == 1){
        ans = min(2*v,u+v);
    }
    else if(diff >= 2){
    }
    else{
        ans = min(u,v);
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
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}