#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll x,y;
    cin>>x>>y;

    if(y<x){
        cout<<0<<" "<<0<<endl;
        return;
    }
    else if(x == y){
        cout<<3<<" "<<1<<endl;
    }
    else{
        ll ans = y/x;
        if(y%x == 0)    {
            ll b = ans;
            ll a = 1;
            cout<<a<<" "<<b<<endl;
        }
        else{
            cout<<0<<" "<<0<<endl;
        }
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