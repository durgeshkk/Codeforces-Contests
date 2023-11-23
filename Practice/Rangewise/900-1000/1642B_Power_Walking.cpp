#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    vector<ll> v;

    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }

    sort(v.begin(),v.end());

    map<ll,ll> mp;
    for(auto it=0; it < n;it++){
        mp[v[it]]++;
    }
/*
    for(auto it = mp.begin();it != mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
*/
    ll freq = 0,ele = mp.begin()->first;
    for(auto it = mp.begin(); it != mp.end();it++){
        if(freq < it->second){
            ele = it->first;
            freq = it->second;
        }
    }

    ll k=1;
    while (k <= (mp.size()))
    {
        // Print no of distinct ele
        cout<<mp.size()<<" ";
        k++;
    }

    // Now print remaining elements increasing by 1
    while (k <= n)
    {
        cout<<k<<" ";
        k++;
    }
    cout<<endl;

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