#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll f=0;
    ll cnt = 0;
    ll mx = 0;
    ll ans = n;
    ll freq = 0;

    for(ll i = 0;i<s.size()-1;++i){
        if(s[i] == ')' and s[i+1] == '('){
            --ans;
        }
    }

    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
   }
   return 0;
}

// SOL 1:
/*
    vector<ll> v = {0};
    for(ll i=0;i<s.size();i++){
        if(s[i] == '('){
            ++cnt;
            // mx = max(mx,cnt);
        }
        else{
            --cnt;
        }

        if(cnt == 0){
            v.push_back(i+1);
            ++freq;
        }
    }

    --freq;
    cout<<(n-freq+1)<<endl;
    return;
    // ll ans = 0;
    if(v.size() == 2){
        ll val = (v[1]/2);
        cout<<val<<endl;
        return;
    }

    show(v);
    
    for(ll i= 1;i<v.size();++i){
        ll val = (v[i]-v[i-1])/2;
        ans += (val-1);
    }
    cout<<ans+1<<endl;
    return;
    // if(f == 1){
    //     cout<<ans<<endl;
    // }
    // else{
    //     cout<<(ans-1)<<endl;
    // }
    
*/

// SOL 2:
/*

    for(ll i=0;i<s.size();i++){
        if(s[i] == '('){
            ++cnt;
            mx = max(mx,cnt);
        }
        else{
            --cnt;
        }

        if(cnt == 0){
            ++f;
            ++freq;
            ans += mx;
            mx = 0;
            cnt = 0;
        }
    }
    
    --freq;
    cout<<(ans-freq)<<endl;
*/