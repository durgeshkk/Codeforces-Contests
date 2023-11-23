#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    // ll size;
    // cin >> size;

    vector<long long> v;
    for (ll i = 0; i < 7; i++)
    {
        long long s;
        cin >> s;
        v.push_back(s);
    }

    long long first = v[0];
    long long second = v[1];
    long long third = v[2];

    if(first+second == v[2]){
        third = v[3];
    }

    cout<<first<<" "<<second<<" "<<third<<endl;
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