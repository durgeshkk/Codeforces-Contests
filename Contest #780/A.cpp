#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    ll a,b;
    cin>>a>>b;

    if(a <= 0){
        cout<<1<<endl;
        return;
    }
    ll ans = (a*1 + b*2);
    cout<<ans+1<<endl;
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