#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
bool isPrime(ll n){
    for(ll i=2;i<n;i++){
        if(n%i == 0){
            // cout<<"NO\n";
            return false;
        }
    }
    return true;
}

void solve()
{
 
    ll n,m;
    cin>>n>>m;
    /*
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }*/

    if(isPrime(n) == false){
        cout<<"NO\n";
        return;
    }

    ll myprime = 0;
    for(ll i=n+1;i<=m;i++){
        if(isPrime(i) == true){
            myprime = i;
            break;
        }
    }

    if(m == myprime){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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
//        solve();
//    }
   solve();
   return 0;
}