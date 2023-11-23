#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
    ll n;cin>>n;ll mn = LLONG_MAX, sm = 0;
    multiset<pair<ll,ll>> ms;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;ms.insert({b,a});mn = min(mn,b);sm += a;
    }

    ll items = mn,cst = 2*mn;
    while(items <= sm){
        pair<ll,ll> p = *ms.begin();
        ms.erase(ms.find(p));
        if(p.first > items){
            if(p.first>sm){
                cst += (2*(sm-items));
                break;
            }
            cst += (2*(p.first-items));
            items = p.first;
        }
        if(items+p.second > sm){
            cst += (sm-items);
            break;
        }
        cst += p.second;
        items += p.second;
    }

    ll ans = min(cst,2*sm);
    cout<<ans<<endl;
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