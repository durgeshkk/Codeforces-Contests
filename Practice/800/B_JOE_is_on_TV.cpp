#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin >> n;

  double ans = 0;
  for(ll i =1;i<=n;i++){
    ans += (1.0/i);
  }
  cout<<ans<<endl;
  // return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(12);
    ll t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
  return 0;
}
