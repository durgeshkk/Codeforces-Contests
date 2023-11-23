#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin>>n;

    string s;
    cin>>s;

    map<char,ll> mp;

    for(ll i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    
    ll count=0;
    for(auto i:mp){
        if(i.second%2 != 0){
            count++;
        }
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