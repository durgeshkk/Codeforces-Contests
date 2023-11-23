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
    vector<ll> dk(n,0);
    vector<ll> ag(n,0);

    set<ll> s,s2;
    for(ll i=1;i<=n;i++){
        s.insert(i);
        s2.insert(-1*i);
    }

    ll mx = 0;
    for(ll i=0;i<n;i++){
        if(v[i] > mx){
            dk[i] = v[i];
            ag[i] = dk[i];
            mx = v[i];
            s.erase(s.find(v[i]));
        }
    }

    // show(ag);

    for(ll i=0;i<n;i++){
        if(dk[i] == 0){
            dk[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    show(dk);

/*
    cout<<"HI\n";
    for(ll i= 0;i<dk.size();++i){
        cout<<dk[i]<<" ";
    }
    cout<<"HI\n";
*/
    ll req = -1*v[0];
    // cout<<req<<" ";
    s2.erase(s2.find(req));
    // show(ag);

    // for(auto it:s2){
    //     cout<<it<<" "; 
    // }
    // cout<<endl;


// /*
    for(ll i=1;i<n-1;++i){
        if(ag[i] == 0){
            // auto idx = s2.find(ag[i]);
            // --idx;
            auto idx = s2.upper_bound(-1*v[i]);
            ll val = *idx;
            val *= (-1);
            // cout<<val<<endl;
            if(idx != s2.end()){
                // ag[i] = abs(*(idx));
                ag[i] = val;
            }
            s2.erase(s2.find(*idx));
        }
        else{
            ll z = (-1*v[i]);
            s2.erase(s2.find(z));
            // req = v[i];
        }
    }
    
    if(!s2.empty()){
        ll z = *s2.begin();
        ag[ag.size()-1] = (-1*z);
    }
    show(ag);
// */
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
    //    ++i;
   }
   //solve();
   return 0;
}