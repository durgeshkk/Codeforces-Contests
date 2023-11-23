#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    // ll u,v;
    // cin>>u>>v;

    ll size;
    cin>>size;
    
    string s;
    cin>>s;

    ll non_zero = 0;
    ll sum=0;

    ll i=0;
    while(i<(s.size()-1)){
        sum = sum + (s[i]-'0');
        // cout<<sum<<" ";
        if(s[i] != '0'){
            non_zero++;
        }
        // cout<<non_zero<<endl;
        i++;
    }
    sum = sum + (s[i]-'0');
    // cout<<sum<<" HI ";
    
    ll ans = sum+non_zero;
    cout<<ans<<endl;

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