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

    ll arr[n][n];

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i == j){
                arr[i][j] = 1;
            }
            else if((i+j+1) == n){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = 0;
            }
        }
    }

    if(n%2 != 0){
        ll a = n/2;
        arr[a][n-1] = 1;
        arr[n-1][a] = 1;
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // cout<<endl;
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