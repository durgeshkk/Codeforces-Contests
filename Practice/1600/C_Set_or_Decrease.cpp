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
#define enter(a) for(ll i=1;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
#define dis(a)  cout<<a<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll flur(ll a, ll b) {
	ll val = a / b;
	while (val * b > a)
		val--;
	return val;
}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
void solve(){
 
    ll n,k;cin>>n>>k;
    vector<ll> v(n+1);
    enter(v);
    ll sum = 0, mn = LLONG_MAX;
    sort(v.begin(),v.end());
    for(ll i=1;i<=n;i++){sum+=v[i];mn = min(mn,v[i]);}
    if (sum <= k){
        dis(0);
		return;
	}

	if (sum == k + 1){
        dis(1);
		return;
	}
	ll diff = sum - k, ans = sum - k;
	sum = 0;
	for (ll i = n; i > 1; i--){
		sum += v[i];
		ll x;
		if(sum - (n - i + 1)*v[1] >= diff)x = 0;
		else x = max(ceil_div(diff - sum + (n - i + 1) * v[1], n - i + 2), 0LL);
		ans = min(ans, x + n - i + 1);
		// cout << x + n - i + 1 << "\n";
	}
    dis(ans);
    // Sol 2:
    /*
    vector<ll> pre(n+1,0);
    for(ll i=0;i<n;i++){pre[i+1]=pre[i]+v[i];sm+=v[i];mn = min(mn,v[i]);}
    if(k >= sm){dis(0);}
    else{
        ll ans = LLONG_MAX;
        for(ll i = 0;i<n;++i){
            ll x = mn-flur((k-pre[n-i]+mn),(i+1));
            // ll x = mn-ceil(1.0*(k-pre[n-i]+mn)/(i+1));
            ans = min(ans,i+max(x,0ll));
        }dis(ans);
    }*/
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
// Everything is same but somesmall thing is missing
/*
        if(k >= n){
            ll avg = k/n;
            ll op = 0;
            ll val = sm;

            if(mn > avg){
                op += (mn-avg);
                sm -= op;
            }

            for(ll j = n-1;j>=0;--j){
                if(sm > k){
                    sm -= (v[j]-avg);
                    ++op;
                }else{break;}
            }

            reverse(v.begin(),v.end());
            sm = val;
            sm -= mn;
            op = min(op,(sm+mn-k));
            // dis(op);
            for(ll j = 0;j<n-1;++j){
                sm -= v[j];
                ll coeff = ceil(1.0*(sm-k)/(j+2));
                coeff = abs(coeff);
                ll ans = (coeff+mn+j+1);
                op = min(op,ans);
            }
            dis(op);
        }else{
            reverse(v.begin(),v.end());
            sm -= mn;
            ll op = (sm+mn-k);
            // dis(op);
            for(ll j = 0;j<n-1;++j){
                sm -= v[j];
                ll coeff = ceil(1.0*(sm-k)/(j+2));
                coeff = abs(coeff);
                ll ans = (coeff+mn+j+1);
                op = min(op,ans);
            }
            dis(op);
        }
        */
    