#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);
void solve()
{

    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<ll> p(n);
    map<ll, ll> mp, mp2;
    set<ll> st;
    for (ll i = 0; i < n; i++){st.insert(i);}

    vector<bool> vis(n + 1);
    for (ll j = 0; j < q; j++){
        ll t;cin >> t;

        if (t == 2){
            ll r;cin >> r;
            cout << v[r - 1] << endl;
        }
        else
        {
            ll l, r;cin >> l >> r;
            l--;r--;

            if(st.empty()){
                continue;
            }

            auto f = st.lower_bound(l);
            set<ll> m;
            for (auto &it = f; it != st.end(); it++){
                if(*it > r){
                    break;
                }

                p[*it]++;
                string t = to_string(v[*it]);
                ll tot = 0;
                for (ll k = 0; k < t.size(); k++){
                    tot += (t[k] - '0');
                }
                v[*it] = tot;
                if (p[*it] == 3)
                {
                    auto g = it;
                    m.insert(*it);
                }
            }
            for (auto it : m)
            {
                st.erase(it);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}