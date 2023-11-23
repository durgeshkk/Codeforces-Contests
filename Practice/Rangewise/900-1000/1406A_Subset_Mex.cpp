#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    set<ll> s;
    vector<ll> v;
    map<ll,ll> mp;
    ll count0 = 0;

    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
       s.insert(ele);
        mp[ele]++;
       if(ele == 0){
           count0++;
       }
    }

    sort(v.begin(),v.end());
/*

    if(count0 == 0){
        cout<<0<<endl;
    }
    else if(count0 == 1){

        for(ll i=0;i<=v[v.size()-1];i++){
            if((mp[i] == 0)){
                cout<<i<<endl;
                return;
            }
        }
        cout<<s.size()<<endl;

    }
    else{
        ll ans1 = 0,f=0;
        for(ll i=0;i<=v[v.size()-1];i++){
            if((mp[i] == 0)){
                f=1;
                ans1 = i;
                break;
            }
        }

        if(f == 0){
            ans1 = s.size();
        }

        for(ll i=0;i<n;i++){
            if((mp[v[i]] == 1) || (mp[v[i]] == 0)){
                cout<<ans1+v[i]<<endl;
                return;
            }
        }
        cout<<2*ans1<<endl;
    }*/

    /*
    Also can be done directly by creating freq
    array. If freq[i] is found 1 toh aage ek ka mex
    will stop & 2nd ka mex will continue till
    freq[i] >= 1..
    */

   if(count0 == 0){
       cout<<0<<endl;
       return;
   }
   else if(count0 == 1){
       for(ll i=0;i<=v[v.size()-1];i++){
            if((mp[i] == 0)){
                cout<<i<<endl;
                return;
            }
        }
        cout<<s.size()<<endl;
        return;
   }

   ll ans1 = 0;
   ll ans2 = 0,f=0;

        for(ll i=0;i<=v[v.size()-1];i++){
            if((mp[i] == 0)){
                cout<<ans1+ans2<<endl;
                return;
            }
            else if(mp[i] == 1){
                f = 1;
                ans2++;
            }
            else if(mp[i] >= 2 && f==0){
                ans1++;ans2++;
            }
            else if(mp[i] >= 2 && f==1){
                ans2++;
            }
        }

        cout<<ans1+ans2<<endl;

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