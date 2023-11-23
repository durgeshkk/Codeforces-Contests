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

    string s;
    cin>>s;

    vector<pair<ll,ll>> v;
    ll dk= 0;

    for(ll i = 0;i<n;++i){
        ll z = (n-i-1);
		if(s[i]=='R'){
			dk += z;
			if(z<i){
                v.push_back({i,z});
            }
		} 
        else{
			dk+=i;
			if(z>i){
                v.push_back({z,i});
            }
		}
	}

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    ll sz =v.size();
	ll ak = 0;

    for(ll i = 0;i<n;++i){
		if(ak < sz) {
			dk+=v[ak].first;
			dk-=v[ak].second;
			cout<<dk<<" ";
			ak++;
	    }
        else{
			cout<<dk<<" ";
		}
	}
    cout<<endl;
 
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