#include<bits/stdc++.h>
#include<iomanip>
#include <bitset>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
    
    string s;
    cin>>s;
    
    ll n = s.size();

    ll q;
    cin>>q;
    
    set<pair<string,ll>> ag;
    map<string,ll> mp;
    for(ll i=0;i<q;i++){
        string st;
        cin>>st;
        mp[st] = (i+1);
        ag.insert({st,i+1});
    }

    vector<pair<ll,ll>> ans;
 
    ll mx = -1;
    for(ll i=0;i<n;++i){
        ll f = 0;
        string dk = s.substr(i,n);
        for(ll j = n;j>i;--j){
            if(mp.find(dk) != mp.end()){
                ans.push_back({mp[dk],i+1});
                (mx = (j-1));
                f = 1;
            }
            dk.pop_back();
        }

        if(mx >= i){
            continue;
        }

        if(f == 0){
            cout<< -1 <<endl;
            return;
        }
    }

    if(mx == -1){
        cout<<mx<<endl;
    }
    else{
        cout<<ans.size()<<endl;
        for(auto it:ans){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}