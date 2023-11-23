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

    ll one = 0,zero=0;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];

       if(v[i] == 0){
           zero++;
       }
       else{
           one++;
       }
    }

    vector<ll> ans;

    if(zero >= one)
    {
        cout<<zero<<"\n";
        for(ll i = 0;i<zero;i++){
            cout<<0<<" ";
        }
        cout<<endl;
    }
    else{
        if(one&1){//if one's are odd & also 1>0
            one--;
        }
        cout<<one<<endl;
        for(ll i = 0;i<one;i++){
            cout<<1<<" ";
        }
        cout<<endl;
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