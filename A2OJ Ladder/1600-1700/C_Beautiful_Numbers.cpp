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
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll n,a,b;

ll sod(string st){
    ll sm = 0;
    for(ll i = 0;i<st.size();++i){
        sm += (st[i]-'0');
    }
    return sm;
}

ll ans = 0;
void recur(ll idx,string s){
    if(idx == n){
        // cout<<s<<" ";
        // Now here check if sum of digit in s is gd no.
        ll sm = sod(s);
        // cout<<sm<<" ";
        string st = to_string(sm);
        // cout<<st<<endl;

        for(auto it:st){
            if(((it-'0') != a) and ((it-'0') != b)){return;}
        }
        ++ans;ans %= mod;
        return;
    }

    string tmp=s;
    tmp += (a+'0');
    recur(idx+1,tmp);tmp.pop_back();
    
    tmp += (b+'0');
    recur(idx+1,tmp);
    return;
}

ll printNcR(ll n, ll r)
{
	long long int p = 1, k = 1;
	if (n - r < r)
		r = n - r;

	if (r != 0) {
		while (r) {
            p = mod_mul(p,n,mod);
			// p *= n;
            k = mod_mul(k,r,mod);
			// k *= r;

			long long int m = __gcd(p, k);

			p /= m;k /= m;
			n--;r--;
		}
	}
	else
		p = 1;

    return p;
	cout << p << endl;
}


ll power(ll base,ll n,ll mod){
   ll ans = 1;
   while( n!= 0){
      if(n%2){
          n-=1;
          ans = (ans*base)%mod;
      }
      else{
          n /= 2;
          base = (base*base)%mod;
      }
   }
   return ans;
}
 
ll fact[1000005];
ll powfact[1000005];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=1000005;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
         powfact[i] = power(fact[i],mod-2,mod);
    }
    powfact[0] = 1;
}
 
ll nCr(ll n,ll r){
    ll at = powfact[r];
    ll at2 = powfact[n-r];
    at = mod_mul(at,at2,mod);
    ll ele = mod_mul(at,fact[n],mod);
    return ele;
}

void solve()
{
    cin>>a>>b;cin>>n;
    ll ans = 0;
    /*
    Recursive Solution :
    recur(0,"");
    */

    // Mathematical Solution :
    for(ll i = 0;i<=n;++i){
        // Assume we have i a's & no. to be good we need (n-i) b's
        ll sum_of_dig = i*a+(n-i)*b;
        string st = to_string(sum_of_dig);
        ll f = 1;
        for(auto it:st){
            if(((it-'0') != a) and ((it-'0') != b)){
                f = 0;break;
            }
        }

        if(f & 1){
            ll ele = 0;
            // ele will be all permutations of a i's and b (n-i)'s
            ele = nCr(n,max(i,n-i));
            ans = mod_add(ans,ele,mod);
            // ele = printNcR(n,max(i,n-i));
            // ans += ele;
            // ans %= mod;
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
   precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
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




