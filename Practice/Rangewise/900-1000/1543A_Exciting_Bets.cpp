#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll a,b;
    cin>>a>>b;

    if(a==b){
        cout<<0<<" "<<0<<endl;
        return;
    }

    if(a==0 || b==0){
        cout<<abs(a-b)<<" "<<0<<endl;
        return;
    }
    ll diff = abs(a-b);
    ll ans1 = a%diff;
    ll ans2 = diff-ans1;

    ll ans = min(ans1,ans2);
    cout<<diff<<" "<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}