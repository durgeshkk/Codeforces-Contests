#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    ll n,h;
    cin>>n>>h;

    vector<int> v;

    for (ll i = 0; i < n; i++)
    {
        ll ele;
        cin>>ele;

        v.push_back(ele);
    }

    sort(v.begin(),v.end());

    ll sum = accumulate(v.begin(),v.end(),0);
    
    if(h < v[v.size()-1]){
        cout<<1<<endl;
        return;
    }

    ll count = 0;
    while(!v.empty() && h>0){
        if(h < v[v.size()-1]){
            break;
        }
        h = h - v[v.size()-1];
        v.pop_back();
        count++;
    }
    cout<<count<<endl;

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