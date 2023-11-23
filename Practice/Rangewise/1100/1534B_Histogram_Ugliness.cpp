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
    vector<ll> v(n);
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

// calculate total ugliness
    ll total = 0;
    for(ll i =0;i<n;i++){
        if(i == 0){
            total += v[i];
        }
        else{
            total += abs(v[i]-v[i-1]);
        }
    }
    total += v[n-1];

    for(ll i = 1;i<n-1;i++){
        if(v[i] > v[i-1] && v[i]>v[i+1]){
            total -= abs(max(v[i-1],v[i+1]) - v[i]);
            // Update height of curr bar
            v[i] = max(v[i-1],v[i+1]);
        }
    }

    // Corner Cases : 
    if(n>1){
        // For 1st bar
        if(v[0] > v[1]){
            total -= abs(v[1]-v[0]);
        }
        // For last bar
        if(v[n-1] > v[n-2]){
            total -= abs(v[n-1]-v[n-2]);
        }
    }
    else{
        total = v[0];
    }
    cout<<total<<endl;

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