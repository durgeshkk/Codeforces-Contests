#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    set<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.insert(ele);
    }

    if(v.size() == n){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
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