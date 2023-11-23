#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    string s;
    if(n==1){
        cout<<9<<endl;
        return;
    }

    if(n==2){
        cout<<98<<endl;
        return;
    }

    vector<ll> v(n,8);//initialise vector with 8
    ll x=1;
    for(ll i=0;i<n;i++){
        v[i] = (v[i]+abs(i-x))%10;
        cout<<v[i];
    }
    cout<<endl;

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