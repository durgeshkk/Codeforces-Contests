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

    if(v.size() == 1){
        cout<<"YES\n";
        return;
    }
    
    else if(v.size() == 2){
        if((v[1] - v[0]) <= 3){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return;
    }
/*
    for(ll i=1;i<n-1;i++){
        ll l_diff = v[i]-v[i-1];
        ll r_diff = v[i+1]-v[i];

        ll mn = min(l_diff,r_diff);
        ll mx = max(l_diff,r_diff);

        if(mn == 2 && mx == 2){
            continue;
        }
        if((mx > 3) ||( mn != 1)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";*/
/* 2nd appr : 
    map<ll,ll> mp;
    mp[1] = 0;
    mp[2] = 0;
    mp[3] = 0;
    ll f=0;

    for(ll i=0;i<n-1;i++){
        ll diff = v[i+1]-v[i];

        if((v[n-1] - v[n-2]) == 2){
            f=1;
        }
        mp[diff]++;
    }

    if(mp.size() > 3){
        cout<<"NO\n";
    }
    else if(mp[3] >= 2){
        cout<<"NO\n";
    }
    else if((mp[2] > 2)){
        cout<<"NO\n";
    }
    else if((mp[2] >= 2) && (f==0)){
        cout<<"NO\n";
    }
    else if((mp[2] == 1) && (mp[3] == 1)){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    */
// /*
    ll count = 0;
    ll flag = 0;

    for(ll i=0;i<n-1;i++){
        ll diff = v[i+1]-v[i];

        if(diff > 3){
            cout<<"NO\n";
            return;
        }

        if(diff == 3){
            flag = 1;
        }

        if(diff > 1){
            count++;
        }
    }

    if((flag == 0 && count > 2)||(flag == 1 && count>1)){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
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