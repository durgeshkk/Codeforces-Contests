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
       mp[v[i]]++;
    }

    ll mx = *max_element(v.begin(),v.end());
    if(mp[mx] == 1){
        cout<<1<<endl;
        return;
    }
    
    ll cnt = 0;
    ll cns = 0;
    for(ll i=0;i<n;i++){
        if(mx == v[i]){
            cnt++;
        }
        else{
            cnt = 0;
        }

        if(cnt > cns){
            cns = cnt;
        }
    }

    cout<<cns<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    ll t;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
   solve();
   return 0;
}