#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    ll size;
    cin>>size;

    string s;
    cin>>s;

    ll i=0;
    while(i<s.size()){
        if(s[i] == 'L'){
            cout<<"L";
        }
        else if(s[i] == 'R'){
            cout<<"R";
        }
        else if(s[i] == 'U'){
            cout<<"D";
        }
        else if(s[i] == 'D'){
            cout<<"U";
        }
        i++;
    }
    cout<<endl;
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