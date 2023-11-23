#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll a[5][5];
    for(ll i=0;i<5;i++){
        for(ll j=0;j<5;j++){
            ll ele;
            cin>>ele;
            a[i][j] = ele;
        }
    }
/*
    for(ll i=0;i<5;i++){
        for(ll j=0;j<5;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(ll i=0;i<5;i++){
        for(ll j=0;j<5;j++){
            if(a[i][j] == 1){
                cout<<abs(i-2)+abs(j-2)<<endl;
                return;
            }
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