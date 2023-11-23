#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    string s;
    cin>>s;

    if(s.size() <= 1){
        cout<<"NO\n";
        return;
    }

    ll i=0;
    ll A_size=0,B_size=0,C_size=0;

    while(i<s.size()){
        if(s[i] == 'A'){
            A_size++;
        }
        if(s[i] == 'B'){
            B_size++;
        }
        if(s[i] == 'C'){
            C_size++;
        }
        i++;
    }

    if(B_size == (A_size+C_size)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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