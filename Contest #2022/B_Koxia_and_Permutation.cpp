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
   ll i = 1;
   while (t--){
       ll n,k;cin>>n>>k;
        vector<ll> dyno(n,0);
        if(n%2 == 0){
            ll i = 1;
            for(ll j=1;j<n;j+=2,++i){
                dyno[j] = i;
            }
            for(ll j=n-2;j>=0;j-=2,++i){
                dyno[j] = i;
            }
        }else{
            ll i = 1;
            for(ll j=1;j<n;j+=2,++i){
                dyno[j] = i;
            }
            for(ll j=n-1;j>=0;j-=2,++i){
                dyno[j] = i;
            }
        }

        forj(n){
            cout<<dyno[j]<<" ";
        }cout<<endl;
   }
   return 0;
}