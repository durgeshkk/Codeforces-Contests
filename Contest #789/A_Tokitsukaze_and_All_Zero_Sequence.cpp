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
    ll countz = 0;
    map<ll,ll>  mp;
    for(ll i=0;i<n;i++){
       cin>>v[i];
        mp[v[i]]++;
        if(v[i] == 0){
            countz++;
        }
    }
/*
    for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
*/

    if(countz > 0){
        cout<<(n-countz)<<endl;
        return;
    }
    else{
        for(ll i = 0;i<n;i++){
            if(mp[v[i]] >= 2){
                cout<<n<<endl;
                return;
            }
        }
        cout<<n+1<<endl;
        return;
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