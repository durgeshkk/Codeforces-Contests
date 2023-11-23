#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m;
    cin>>n>>m;


    ll a[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
/*
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    ll neg_ele = 0;
    bool zero = false;
    ll pos_ele=0;
    ll mn = INT16_MAX;
    ll sum = 0;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(a[i][j] > 0){
                pos_ele++;
            }
            else if(a[i][j] < 0){
                neg_ele++;
            }
            else{
                zero = true;
            }

            if(mn > abs(a[i][j])){
                mn = abs(a[i][j]);
            }

            sum += abs(a[i][j]);
        }
    }

    if(neg_ele%2 != 0 && zero == false){
        cout<<sum - (2*mn)<<endl;
    }
    else{
        cout<<sum<<endl;
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
   //solve();
   return 0;
}