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

    vector<ll> a(n);
    vector<ll> b(n);
    enter(a);
    enter(b);
 
    multiset<ll> neg,pos;
    ll f = 0;
    for(ll i=0;i<n;i++){
        ll diff = (b[i]-a[i]);
        if(diff > 0){
            pos.insert(diff);
        }
        else if(diff == 0){
            // neg.insert(diff);
            ++f;
        }
        else{
            neg.insert(diff);
        }
    }
    
    if(f & 1){
        neg.insert(0);
    }

    vector<ll> po(pos.begin(),pos.end());
    reverse(po.begin(),po.end());

    ll ans = pos.size()/2;
    ll cnt = 0;
    ll i = 0;
    
    while(neg.size() != 0){
        ll val = *neg.begin();
        neg.erase(neg.find(val));

        if(i == po.size()){
            break;
        }

        ll ag = po[i];
        // cout<<ag<<" "<<val<<endl;

        if((ag + val) < 0){
            // cout<<"HI\n";
            continue;
        }
        else{
            ++cnt;
            ++i;
        }
        // cout<<i<<endl;
    }
    // cout<<cnt<<endl;
    cnt += (po.size()-i)/2;

    ans = max(ans,cnt);
    
    ans += (f/2);
    
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}

/*
    // cout<<ans<<endl;
    for(auto it:neg){
        cout<<it<<" ";
    }
    cout<<endl;
    show(po);
*/
