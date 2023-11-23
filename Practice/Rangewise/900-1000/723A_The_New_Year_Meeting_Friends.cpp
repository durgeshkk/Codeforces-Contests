#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll x1,x2,x3;
    cin>>x1>>x2>>x3;

    ll meet_pt = (x1+x2+x3)/3;

   //  ll ans = abs(meet_pt-x1) + abs(meet_pt-x2) + abs(meet_pt-x3);
   ll ans = max(x1,max(x2,x3)) - min(x1,min(x2,x3));
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
//    cin >> t;
//    while (t--)
//    {
       solve();
//    }
   return 0;
}