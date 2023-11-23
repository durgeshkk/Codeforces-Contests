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
 
void solve(map<ll,ll> mp)
{
 
    ll n;
    cin>>n;
    
    ll c = cbrt(n);
    int f=0;
    for(ll i=1;i<=10000;i++){
        if(f){
            break;
        }

        ll z = i*i*i;

        if(z>=n){
            break;
        }

        if(mp.find(n-z) != mp.end()){
            f = 1;
        }
    }

    if(!f){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    return;
}
 
int main()
{
    map<ll,ll> mp;
    mp[0]=0;
    for(ll i=0;i<10001;i++){
        mp[i*i*i]++;
    }

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve(mp);
   }
   //solve();
   return 0;
}