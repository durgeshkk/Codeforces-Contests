#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m;
    cin>>n>>m;

    vector<pair<ll,ll>> v;
    for(ll i=0;i<(2*n);i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }

    if(m%2 != 0){
        cout<<"NO\n";
        return;
    }
    else if(m == 2){
        
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
   return 0;
}