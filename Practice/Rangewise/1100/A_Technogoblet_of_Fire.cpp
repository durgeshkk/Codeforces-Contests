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
 
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }
    
    map<ll,ll> mp;

    vector<ll> s(n);
    for(ll i=0;i<n;i++){
       cin>>s[i];
       mp[s[i]] = 0;
    }

    vector<ll> dk(k);
    for(ll i = 0;i<k;i++){
        cin>>dk[i];
    }

    for(ll i=0;i<n;i++){
        if(mp[s[i]] < v[i]){
            mp[s[i]] = v[i];
        }
    }

    ll cnt = 0;
    for(ll i = 0;i<k;i++){
        ll idx = (dk[i]-1);

        ll ele = s[idx];
        ll val = v[idx];

        if(val < mp[s[idx]]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}