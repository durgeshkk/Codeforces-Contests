#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll z;
    cin>>z;

    vector<ll> v1;

    for(ll i=0;i<z;i++){
        ll ele;
        cin>>ele;
        v1.push_back(ele);
    }

    vector<ll> v2;
    for(ll i=0;i<z;i++){
        ll ele;
        cin>>ele;
        v2.push_back(ele);
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    ll diff = 0;
    for(ll i=0;i<z;i++){
        ll a = (v1[i]-v2[i]);
        if((a > 0) || (a<=-2)){
            cout<<"NO\n";
            return;
        }
        diff += (v1[i]-v2[i]);
    }

    if(abs(diff) > z){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
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