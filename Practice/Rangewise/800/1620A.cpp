#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll count_n=0;

    string s;
    cin>>s;

    ll i=0;
    while(i < s.size()){
        if(s[i] == 'N'){
            count_n++;
        }
        i++;
    }

    if(count_n == 1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
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