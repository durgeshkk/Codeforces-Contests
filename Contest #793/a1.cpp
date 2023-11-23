#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin >> s;

    ll t2 = n/2;
    // cout<<t2<<endl;

    char ch = s[t2];
    // cout<<ch<<endl;

    ll cnt = 0;
    
    if(n%2){
        for (ll i = t2; i < n; i++)
        {
            if(ch != s[i]){
                break;
            }
            cnt++;
        }

        for (ll i = t2-1; i >= 0; i--)
        {
            if(ch != s[i]){
                break;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    else{
        
        for (ll i = t2; i < n; i++)
        {
            if(ch != s[i]){
                break;
            }
            cnt++;
        }

        for (ll i = t2-1; i >= 0; i--)
        {
            if(ch != s[i]){
                break;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }

    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}