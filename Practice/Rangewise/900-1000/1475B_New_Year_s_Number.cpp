#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    ll t = n/2020;
    /*
    ll y = n%2020;
    double x = y + (1.0*n/2020);
    ll ans = y + (n/2020);
    cout<<"X : "<<x<<" "<<"ans "<<ans<<endl;*/

    ll y = n%2020;
    ll x = t-y;

    if(x>=0 && y>=0){
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
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}