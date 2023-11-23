#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m;
    cin>>n>>m;

    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }

    if(n > m){
        cout<<"NO\n";
        return;
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    ll sum = n;
    sum = sum + (v[0]*2);

    if(n == 2){
        if(sum <= m){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return;
    }


    for(ll i=1;i<n-1;i++){
        sum += v[i];
    }

    if(sum <= m){
        cout<<"YES\n";
    }
    else{
        // cout<<"NO HIIE\n";
        cout<<"NO\n";
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