#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll x,y;
    cin>>x>>y;

    ll ans = (y%x);

    ll power=x;
    while(power <= y){
        power = power*10;
    }
    power = power/10;

    while(power >= x){
        ans = ans + (y/power);
        y = y%power;
        power = power/10;
    }

    cout<<ans<<endl;
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