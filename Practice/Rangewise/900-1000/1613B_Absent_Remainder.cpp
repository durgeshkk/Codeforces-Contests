#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    ll num_req = n/2;
    ll count = 0;

    vector<ll> v;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
        mp[ele]++;
    }

    sort(v.begin(),v.end());
    /*
    for(auto i=mp.begin();i != mp.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    */

   for(ll i=0;i<n;i++){
       ll a = v[i];
       for(ll j=i+1;j<n;j++){
           ll b = v[j];

           if(mp.find(b%a) == mp.end()){
            //    mp[bx%a]++;
               cout<<b<<" "<<a<<endl;
               count++;
           }

           if(count == num_req){
               return;
           }
       }
   }

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}