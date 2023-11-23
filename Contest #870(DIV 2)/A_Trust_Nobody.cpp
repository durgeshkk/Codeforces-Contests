#include<bits/stdc++.h>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
using namespace std;
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n,0);
    ll zeroes = 0;
    for(ll i = 0;i<n;++i){
        cin>>v[i];
        if(!v[i]){++zeroes;}
    }
    sort(v.begin(),v.end());

    if(zeroes == n)
    {
        cout<<0<<endl;
        return;
    }

    ll neg = -1;
    for(ll i = 0;i<=n;++i){
        ll sach = 0,jooth = 0;
        for(ll j = 0;j<n;++j){
            if(v[j] > i){++sach;}
            else{++jooth;}
        }

        if(i == sach){
            cout<<sach<<endl;return;
        }
    }
    cout<<neg<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   return 0;
}