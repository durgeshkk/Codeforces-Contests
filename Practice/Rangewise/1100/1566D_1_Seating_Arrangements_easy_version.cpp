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
 
    ll n,m;
    cin>>n>>m;

    vector<ll> v(m);
    for(ll i=0;i<m;i++){
       cin>>v[i];
    }

    ll ans = 0;
    for(ll i =1;i<m;i++){
        for(ll j = 0;j<i;j++){
            if(v[i] > v[j]){
                ans++;
            }
        }
    }

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