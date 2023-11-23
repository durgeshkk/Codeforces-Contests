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
 
    ll n,x,t;
    cin>>n>>x>>t;
    
    /*Long approach
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        v[i] = (i*x);
    }

    vector<ll> tym(n);
    // tym[0] = t;
    for(ll i=0;i<n;i++){
        tym[i] = ((i*x)+t);
    }

    ll count = 0;
    ll j = 0;
    for(ll i=0;i<n;i++){
        ll req = tym[i];
        j = i+1;
        if(j == n){
            j = i+1;
            continue;
        }
        if(tym[i]*x >= tym[j]){
            count++;
        }
        else{

        }         
    }

    cout<<count<<endl;*/
    
    // Smart Approach : 
    ll z = t/x;

    if(n < z){
        cout<<n*(n-1)/2<<endl;
    }
    else{
        ll ans = (n*z) - (z*(z+1)/2);
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