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
        v.push_back(ele%n);
    }

    ll sum = 0;
    for(ll i=0;i<n;i++){
        sum += v[i];
        sum %= n;
    }

    // ll sum = accumulate(v.begin(),v.end(),0);
    ll extra_cars = (sum%n);
    ll empty = n-extra_cars;

    cout<<extra_cars*empty<<endl;

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