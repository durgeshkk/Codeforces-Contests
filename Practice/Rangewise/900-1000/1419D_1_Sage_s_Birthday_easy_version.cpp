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
    ll count = (n-1)/2;
    cout<<count<<endl;

    vector<ll> small,big;

    for(ll i=0;i<count;i++){
        small.push_back(v[i]);
    }
    
    for(ll i=count;i<n;i++){
        big.push_back(v[i]);
    }

    vector<ll> ans;
    for(ll i=0;i<count;i++){
        ans.push_back(big[i]);
        ans.push_back(small[i]);
    }

    
    if(n%2){
        for(ll i=0;i<n-1;i++){
            cout<<ans[i]<<" ";
        }
        cout<<v[v.size()-1];
    }
    else{
        for(ll i=0;i<n-2;i++){
            cout<<ans[i]<<" ";
        }
        cout<<v[v.size()-2]<<" ";
        cout<<v[v.size()-1];
    }
    cout<<endl;
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
//        solve();
//    }
   solve();
   return 0;
}