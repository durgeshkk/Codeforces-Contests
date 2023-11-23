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
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    map<ll,ll> mp;

    for(ll i=0;i<n;i++){
       cin>>v[i];
       mp[v[i]]++;
    }

    sort(v.begin(),v.end());

    ll x = v[n-1];
    ll y = 1;
    int f = 0;

    for(ll i = n-1;i>=0;i--){
        if(x % v[i]){
            y = v[i];
            f = 1;
            break;
        }
    }

    if(f == 0){
        ll t = 1;
        for(auto it = mp.begin(); it!=mp.end();it++){
            if(it->second == 2){
                t = (it->first);
                // cout<<t<<endl;
            }
        }
        y = t;
    }
    cout<<x<<" "<<y<<endl;
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