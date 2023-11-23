#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;

void solve(){

    ll n, m;
    cin >> n >> m;

    vector<ll> a (n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> f (n+m+1);
    vector<ll> latestUpdated (n+m+1);
    
    ll ans = (n+n) *(m * (m+1))/2;

    for (ll i = 1; i <= m; i++)
    {
        ll ind, val;
        cin >> ind >> val;
        ind--;

        ll num = a[ind];

        f[num] += i - latestUpdated[ind];
        latestUpdated[ind] = i;
        a[ind] = val;
    }
    
    for (ll i = 0; i < n; i++)
    {
        ll num = a[i];
        f[num] += m+1 - latestUpdated[i];
    }
    show(f);
    for (ll i = 0; i < n+m+1; i++)
    {
        ll fre = f[i];

        ans -= (fre*(fre-1))/2;
    }
    
    cout << ans << endl;
}

int main() { 

    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    
    cin >> T;
    
    while (T--)
    {
        solve();
    }
    
    return 0;

}