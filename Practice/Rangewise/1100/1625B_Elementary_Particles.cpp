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
    int a[n];
    // vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>a[i];
    }
/* TLE:
    ll len = -1,max = -1;
    for(ll i=0;i<n;i++){
        for(ll j = i+1;j<n;j++){
            if(v[i] == v[j]){
                len = min(j,n-j-1+i+1);
                if(max < len){
                    max = len;
                }
            }
        }
    }*/
    ll ans = -1;

    map<ll,ll> mp;

// In case of more than twice occuring element we will choose the last 2nd occuring ele
// as it will maximise left side length..Thus we can update AS mp[a[i]] = i
// 1....1....1...
// 1 : 0->5 & so on gets updates

    for(ll i=0;i<n;i++){
        if(mp.count(a[i])){
            // Left side length = mp[a[i]],i.e.ind
            // Right side length depends on next occuring ele = (n-i)
            ans = max(ans,(mp[a[i]]+n-i));
        }
        mp[a[i]] = i;//store ind in map
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