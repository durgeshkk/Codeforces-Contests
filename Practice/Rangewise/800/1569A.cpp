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

    if(s.size() <= 1){
        cout<<-1<<" "<<-1<<endl;
        return;
    }

    ll i=0;

    while(i<s.size()-1){
        if((s[i] == 'a' && s[i+1] == 'b') || (s[i+1] == 'a' && s[i] == 'b')){
            cout<<i+1<<" "<<i+2<<endl;
            return;
        }
        i++;
    }

    i=0;

    while(i<s.size()-3){
        if((s[i] == 'a' && s[i+1] == 'a' && s[i+2] == 'b' && s[i+3] == 'b') || (s[i] == 'b' && s[i+1] == 'b' && s[i+2] == 'a' && s[i+3] == 'a')){
            cout<<i+1<<" "<<i+4<<endl;
            return;
        }
        i++;
    }

    cout<<-1<<" "<<-1<<endl;
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