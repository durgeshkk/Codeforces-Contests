#include <bits/stdc++.h>
#include <deque>
#define ll long long int
#define MOD 998244353
using namespace std;

void solve()
{
    ll n;
    cin>>n;

    if(n%2 == 0){
        ll ans = 1;
        for(ll i=2;i<=n/2;i++){
            ans *= i;
            ans %= MOD;
        }
        ans *= ans;
        ans %= MOD;
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
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