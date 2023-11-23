#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    set<ll> s(v.begin(),v.end());
    // map<ll,ll> mp;
/*
    ll ag = 0;
    for(ll i= 0;i<v.size()-2;++i){
        for(ll j = i+1;j<v.size()-1;++j){
            for(ll k = j+1;k<v.size();++k){
                ll mx = max(v[i],max(v[j],v[k]));
                ll mn = min(v[i],min(v[j],v[k]));

                if(mx - mn <= 2){
                    cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
                    ++ag;
                }
            }
        }
    }
    cout<<"-----\n";
    cout<<ag<<" ";*/
    vector<ll> dk(n+1);
    for(auto it:v){
        dk[it]+=1;
    }
    
    // sort(v.begin(),v.end());

    ll ans = 0;

    for(ll i=2;i<n;++i){
        ans += (dk[i-1]*dk[i]*dk[i+1]);
    }

    for(ll i=2;i<=n;++i){
        ans += (dk[i-1]*(dk[i]*(dk[i]-1)/2));
    }
   
    for(ll i=2;i<n;++i){
        ans += (dk[i-1]*(dk[i+1]*(dk[i+1]-1)/2));
    }

    for (ll i=1;i<n;++i){
        ans += (dk[i+1]*((dk[i]-1)*(dk[i])/2));
    }
    
    for(ll i=2;i<n;++i){
        ans += (dk[i+1]*(dk[i-1]*(dk[i-1]-1)/2));
    }

    for (ll i=1;i<=n;++i){
        ans += (dk[i]*(dk[i]-1)*(dk[i]-2)/6);
    }
    /*
    for(auto it:s){
        ll z = it;
        ll a = upper_bound(v.begin(),v.end(),z+2)-v.begin();
        ll b = lower_bound(v.begin(),v.end(),z)-v.begin();
        if(a-b >= 3){
            ll val = ((a-b)*(a-b-1)*(a-b-2)/6);
            ans += val;
        }
    }

    vector<ll> dk(s.begin(),s.end());
    for(ll i = 1;i<dk.size()-1;++i){
        ll ak = mp[dk[i]];
        ll ag = mp[dk[i+1]];
        ll sm = (ak+ag);
        if((sm) >= 3){
            ll val = ((sm-2)*(sm-1)*(sm)/6);
            ans -= val;
        }
    }*/
    cout<<ans<<endl;
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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
    //    cout<<"Case #"<<i<<": ";
       solve();
       ++i;
   }
   //solve();
   return 0;
}