/*
      Author : ME
*/
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
 
    ll n;cin>>n;
    vector<string> v(2*n);
    enter(v);
    string s;cin>>s;
    map<char,ll> mp;

    // Jo string ans/starting hongi uske sabhi characters ka occurence odd honga!!
    for(ll i = 0;i<2*n;++i){
        string st = v[i];
        for(auto it:st){
            mp[it]++;
        }
    }

    // Remove char occurence which are in final strings
    for(auto it:s){
        mp[it]--;
    }

    string ac;// add odd occurence to it!!
    for(auto it:mp){
        if(it.second & 1){
            ac += it.first;
        }
    }

    sort(ac.begin(),ac.end());
    string ans;
    for(ll i = 0;i<2*n;++i){
        sort(v[i].begin(),v[i].end());
        if(v[i] == ac){
            ans = v[i];
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
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
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