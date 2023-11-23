#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    vector<ll> v;
    map<ll,ll> mp;

    
    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }
    
    sort(v.begin(),v.end());

    for(ll i=0;i<n;i++){
        mp[v[i]]++;
    }

    if(n <= 1){
        cout<<0<<endl;
        return;
    }
    
    ll freq = 1,ele = mp.begin()->first;

    for(auto it = mp.begin();it != mp.end(); ++it){
        if(it->second > freq){
            freq = it->second;
            ele = it->first;
        }
    }

    if(freq == n){
        cout<<0<<endl;
        return;
    }

    ll copy = 0,swap = 0;
    // cout<<ele<<" "<<freq<<endl;
    while(freq < n){
        copy++;
        if((freq*2) > n){
            swap += (n-freq);
            cout<<swap+copy<<endl;
            return;
        }
        if(freq == n){
            swap += freq;
            cout<<swap+copy<<endl;
            return;
        }
        swap += freq;
        freq *= 2;
    }
    cout<<swap+copy<<endl;

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