#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    ll mx = 0,mx_ind=0;

    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
       if(ele > mx){
           mx = ele;
           mx_ind = i;
       }
    }

    ll ans=0;
    ll r_count = 0;
    for(ll i=mx_ind+1;i<n;i++){
        if(i == mx_ind+1){
            ans = v[i];
            continue;
        }

        if(v[i] > ans){
            r_count++;
            ans = v[i];
        }
        else{
            ll num = (ans/v[i]);
            ans = ((num+1)*v[i]);
            r_count += (num+1);
        }
    }


    ll l_count=0;
    ans = 0;
    for(ll i=mx_ind-1;i>=0;i++){
        if(i == (mx-1)){
            ans = (0-v[i]);
            continue;
        }

        if(abs(ans) > abs(0-v[i])){
            l_count++;
            ans = (0-v[i]);
        }
        else{
            ll num = (abs(ans)/v[i]);
            ans = (-((num+1)*v[i]));
            l_count += (num+1);
        }

    }

    cout<<l_count+r_count<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    ll t;
//    cin >> t;
//    while (t--)
//    {
       solve();
//    }
   return 0;
}