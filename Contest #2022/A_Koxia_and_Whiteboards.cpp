#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define forj(n) for (ll j = 0; j < n; j++)

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       ll n,m;cin>>n>>m;
        vector<ll> a(n);
        vector<ll> b(m);
        for(ll i=0;i<a.size();i++) cin>>a[i];
        for(ll i=0;i<b.size();i++) cin>>b[i];
    
        multiset<ll> mp(a.begin(),a.end());
        for(ll i=0;i<m;i++){
            ll ele = *mp.begin();
            mp.insert(b[i]);
            mp.erase(mp.find(ele));
        }
        
        ll dyno= 0;
        while(!mp.empty()){
            ll ele = *mp.begin();
            mp.erase(mp.find(ele));
            dyno+= ele;
        }
        cout<<dyno<<endl;
   }
   return 0;
}