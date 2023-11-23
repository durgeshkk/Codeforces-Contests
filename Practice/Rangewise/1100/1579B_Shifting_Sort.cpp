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

    vector<vector<ll>> ans;

    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    for(ll i=0;i<n;i++){

        int itr = max_element(v.begin(),v.end()) - v.begin();

        if(itr != (n-i-1)){
            ans.push_back({itr+1,n-i,1});
        }

        v.erase(v.begin()+itr);
    }

    cout<<ans.size()<<endl;
    for(auto it : ans){
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
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