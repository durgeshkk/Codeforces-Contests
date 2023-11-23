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
 
    ll n,k;
    cin>>n>>k;
    
    if(n == k){
        cout<<1<<endl;
    }
    else if(k > n){
        ll ans = ceil(1.0*k/n);
        cout<<ans<<endl;
    }
    else{//n>k
        ll x = ceil(1.0*n/k);
        k = k*x;
        ll ans = ceil(1.0*k/n);
        cout<<ans<<endl;
    }

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