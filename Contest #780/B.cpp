#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin>>n;

    vector<ll> v;

    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }

    if(n == 1 && v[0]>1){
        cout<<"NO\n";
        return;
    }

    else if(n == 1 && (v[0]==1)){
        cout<<"YES\n";
        return;
    }
/*
    sort(v.begin(),v.end());
    cout<<"HI\n";
    ll sum = accumulate(v.begin(),v.end(),0);
    ll prev = 0;
    while(sum != 0){
        ll i=0;
        cout<<"HI\n";
        while(v[i] == 0){
            v.pop_back();
            cout<<"HI\n";
            i++;
        }

        cout<<"HI\n";
        if(v.size() == 1 && (v[prev] != 0)){
            cout<<"NO\n";
            return;
        }

        if(prev == (v.size()-1)){
            v[v.size()-2]--;
            prev = v.size()-2;
        }
        else{
            v[v.size()-1]--;
            prev = v.size()-1;
        }
        cout<<"HI\n";
        sort(v.begin(),v.end());            
        // sum = accumulate(v.begin(),v.end(),0);
        sum--;
    }
    cout<<"YES\n";*/

    sort(v.begin(),v.end());


    if(v[v.size()-1] - v[v.size()-2] <= 1){
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