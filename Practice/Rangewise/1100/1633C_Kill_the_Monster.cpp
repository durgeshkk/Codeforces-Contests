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
 
ll myceil(ll a, ll b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    return a / b + 1;
}

void solve()
{
 
    ll h,at;
    cin>>h>>at;

    ll hm,dm;
    cin>>hm>>dm;

    ll k,w,a;
    cin>>k>>w>>a;


    ll x = myceil(h,dm);
    ll z = (myceil(hm,at));

    if(x >= z){
        cout<<"YES\n";
    }
    else{
        
        for(ll i = 0;i<= k;i++)
        {
            ll r = h + i*a;
            ll s = at + (k-i)*w;

            
            x = myceil(r,dm); 
            z = myceil(hm,s);

            if(x >= z)
            {
               cout<<"YES\n";
               return;
            }
        }
        cout<<"NO\n";
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