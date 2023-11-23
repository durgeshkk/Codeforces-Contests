#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m;
    cin>>n>>m;
    
    ll mx = max(n,m);
    ll mn = min(n,m);

    if(m==1){
        cout<<"NO\n";
        return;
    }

    ll c = n*m;
    ll a = (n*(m-1));
    ll b = (n*(m+1));
    cout<<"YES\n";
    cout<<a<<" "<<b<<" "<<c*2<<endl;
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
//    solve();
   return 0;
}