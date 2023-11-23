#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    string s;
    cin>>s;

    vector<char> v;

    for (ll i = 0; i < 26; i++)
    {
        v.push_back(s[i]);
    }

/*
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;*/

    string s_to_find;
    cin>>s_to_find;

    vector<int> num;

    ll i=0;
    while(i<s_to_find.size()){
        auto it=find(s.begin(),s.end(),s_to_find[i]);
        // cout<<*it<<endl;

        ll ind = it - s.begin() + 1;
        // cout<<ind<<endl;

        // num.push_back(((ind) - '0') + 1);
        num.push_back((ind));
        // num[i] = ind;
        // cout<<num[i]<<endl;
        i++;

    }

    
    // for(auto it:num){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    i=0;
    ll ans=0;
    while(i<num.size()-1){
        ans+= abs(num[i+1]-num[i]);
        i++;
    }

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