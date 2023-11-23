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
    vector<ll> v,s;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
       s.push_back(ele);
    }

    sort(s.begin(),s.end());

    if(n%2){
        for(ll i=n-1;i>=2;i-=2){
            if(v[i]<v[i-1]){
                swap(v[i],v[i-1]);
            }
        }
    }
    else{
        for(ll i=n-1;i>=1;i-=2){
            if(v[i]<v[i-1]){
                swap(v[i],v[i-1]);
            }
        }
    }

    for(ll i=0;i<n;i++){
        if(v[i] != s[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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