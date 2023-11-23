#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    ll idx = -1;
    string st;
    for(ll i = 1;i<=k;++i){
        st+=s[0];
    }
    for(ll i = 0;i<n;++i){
        string a = s.substr(0,i+1);
        string tmp;
        ll val = k/a.size();
        for(ll i = 0;i<val;++i){
            tmp += a;
        }
        val = k%a.size();
        for(ll i = 0;i<val;++i){
            tmp += a[i];
        }
        if(tmp < st){st = tmp;}
    }
    cout<<st<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   solve();
   return 0;
}
    