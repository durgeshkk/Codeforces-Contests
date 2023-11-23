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

vector<ll> nxt;
void printNGE(vector<ll> arr, ll n)
{
    nxt.assign(n,0);
	stack<pair<ll,ll>> s;
	s.push({arr[0],0});
	for (ll i = 1; i < n; i++) {
		if (s.empty()) {
			s.push({arr[i],i});
			continue;
		}
		while (!s.empty() && (s.top().first < arr[i])){
            nxt[s.top().second] = i;
			// cout << s.top().second << " --> " << i << endl;
			s.pop();
		}
		s.push({arr[i],i});
	}
	while (!s.empty()) {
        nxt[s.top().second] = -1e10;
		// cout << s.top().first << " --> " << -1 << endl;
        // cout << s.top().second << " --> " << -1e6 << endl;
		s.pop();
	}
}


vector<ll> prev_gr8;
void prevGreater(vector<ll> arr, int n)
{
	stack<pair<ll,ll>> s;
	s.push({arr[0],0});
    prev_gr8.push_back(-1e10);
	for (ll i = 1; i < n; i++) {
		while (!s.empty() && s.top().first < arr[i])
			s.pop();

        if(s.empty()){
            prev_gr8.push_back(-1e10);
        }else{
            prev_gr8.push_back(s.top().second);
        }
		s.push({arr[i],i});
	}
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);

    prev_gr8.clear();nxt.clear();
    printNGE(v,n);
    prevGreater(v,n);
    
    vector<ll> pref(v);
    for(ll i=1;i<n;i++){
        pref[i] += pref[i-1];
    }

    ll f = 1;
    for(ll i=0;i<n;i++){
        if(v[i] <= 0){continue;}
        // Handle boundary l,r
        ll l;
        if(prev_gr8[i] <= -1e10){
            l = (0);
        }else{
            l = prev_gr8[i]+1; 
        }

        ll r;
        if(nxt[i] <= -1e10){
            r = (n-1);
        }else{
            r = nxt[i]-1; 
        }

        // Handle boundary sm
        ll sm;
        if(l == 0){
            sm = pref[r];
        }else{
            sm = pref[r]-pref[l-1];
        }

        if(v[i] < sm){f = 0;break;}
    }

    if(f & 1){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
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