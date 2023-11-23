#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n,k;
    cin>>n>>k;

    ll time_need = (240-k);

    ll t=1;
    ll time_req = 5;

    while( (time_need>=time_req) && (t<=n) ){
        time_need = time_need - time_req;
        t++;
        time_req = (5*t);
    }

    ll ans = t-1;
    cout<<ans<<endl;

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    solve();
   return 0;
}