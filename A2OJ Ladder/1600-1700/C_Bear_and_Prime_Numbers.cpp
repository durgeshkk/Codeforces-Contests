/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define int long long 
#define ll long long
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

#define MAXN 10000001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (int i=2; i<MAXN; i++)
		spf[i] = i;

	for (int i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (int i=3; i*i<MAXN; i++)
	{
		if (spf[i] == i)
		{
			for (int j=i*i; j<MAXN; j+=i)
				if (spf[j]==j)
					spf[j] = i;
		}
	}
}

map<ll,ll> mp;
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
void getFactorization(int x)
{
	set<int> ret;
	while (x != 1)
	{
		ret.insert(spf[x]);
		x = x / spf[x];
	}

    for(auto it:ret){mp[it]++;}
}

void solve()
{
 
    int n;cin>>n;
    vector<int> v(n);enter(v);
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++){getFactorization(v[i]);}
 
    ll mn = LLONG_MAX,mx = LLONG_MIN;
    for(auto it:mp){
        mn = min(mn,it.first);
        mx = max(mx,it.first);
    }
    
    // cout<<mn<<" "<<mx<<endl;return;

    vector<ll> ans(mx+1,0);
    for(auto it:mp){
        ans[it.first] = it.second;
    }

    for(ll i = 1;i<=mx;++i){
        ans[i] += ans[i-1];
    }
    // show(ans);return;

    ll m;cin>>m;
    for(ll i = 0;i<m;++i){
        ll l,r;cin>>l>>r;
        if(l > mx){
            cout<<0<<endl;continue;
        }
        --l;
        if(r > mx){r = mx;}
        cout<<(ans[r]-ans[l])<<endl;
    }
    return;
}
 
signed main()
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
    sieve();
   ll t=1;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}
