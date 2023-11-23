#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    /*
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }*/
    ll num=n;
    while(1){
        num += 1;
        ll a = num/1000;
        ll b = (num/100) %10;
        ll c = (num/10) %10;
        ll d = num%10;

        if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d){
            cout<<num<<endl;
            return;
        }
    }

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