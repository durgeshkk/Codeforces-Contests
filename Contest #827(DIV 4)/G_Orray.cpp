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

    ll aur = 0;
    for(ll i=0;i<n;i++){
        aur |= v[i];
    }


    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
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
    vector<pair<ll,ll>> ag;

    for(auto it:s){
        ll val = (aur^it);
        ag.push_back({val,it});
    }

    sort(ag.begin(),ag.end());

    vector<ll> ans;
    for(ll i = 0;i<ag.size();++i){
        ans.push_back(ag[i].second);
        dk.erase(dk.find(ag[i].second));
    }
*/

/*
    map<ll,set<ll>> mp;
    // for(ll i=0;i<32;i++){
    //     mp[i] = {0};
    // }

    set<ll> s(v.begin(),v.end());
    multiset<ll> dk(v.begin(),v.end());
    vector<ll> st(s.begin(),s.end());

    ll idx = -1;
    for(ll i=0;i<st.size();i++){
        bitset<35> ag(st[i]);
        for(ll j = 0;j<35;++j){
            if(ag[j] == 1){
                mp[j].insert(st[i]);
                idx = max(idx,j);
            }
        }
    }

    // cout<<idx<<endl;
    // cout<<aur<<endl;
    ll j = LLONG_MAX;
    vector<ll> ans;

    for(ll i = idx;i>=0;--i){

        if(i > j){
            continue;
        }

        set<ll> val = mp[i];

        if(val.size() == 0){
            continue;
        }
        // cout<<i<<" --> ";
        // for(auto it:val){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        ll mx = -1;
        ll z = -1;
        for(auto it:val){
            ll val = (aur&it);
            if(val >= mx){
                mx = val;  // mx holds & value
                z = it;  // z holds that num
            }
        }

        
        // cout<<z<<" ";

        if(s.find(z) != s.end()){
            ans.push_back(z);
            s.erase(s.find(z));
            dk.erase(dk.find(z));
            aur ^= z;
        }

        // cout<<aur<<" ";
        if(aur == 0){
            break;
        }

        bitset<35> mk(aur);// to remove b4 0's
        for(ll k = 0;k<35;++k){
            if(k >= i){
                if(mk[k] == 1){
                    mk[k] = 0;
                }
            }
        }
        
        aur = mk.to_ullong();
        // cout<<aur<<" ";


        bitset<35> ak(aur);
        for(ll k = 0;k<35;++k){
            if(ak[k] == 1){
                j = k;
            }
        }
        // cout<<j<<endl;
    }

    for(auto it:dk){
        ans.push_back(it);
    }

    show(ans);
    */
