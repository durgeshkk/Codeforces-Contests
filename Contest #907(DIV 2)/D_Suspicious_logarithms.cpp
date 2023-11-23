/*
Once in a LifeTime,
Will never let you Down!!
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
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
#include <cassert>
using namespace std;
ll mod = (ll)(1e9+7);
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
// YE DIL MAANGE MORE!!

// 179 1000000000000000000
// Just get the ans for this rest all is correct in solver
void solver()
{
 
    ll left,right;cin>>left>>right;

    vector<ll> v;
    bitset<64> a(left);
    ll idx = 0;
    forj(64){
        if(a[j]){idx = j;}
    }

    bitset<64> b(right);
    ll idx2 = 0;
    forj(64){
        if(b[j]){idx2 = j;}
    }

    for(ll i=idx;i<=idx2;i++){v.push_back(i);}

    ll ans = 0;
    forj(v.size()){
        // Handle for [0,n-1]
        ll bande = pow(2,v[j]);
        ll sa = 0;
        ll l = bande,r = (2*l)-1;

        if(j == 0){
            l = max(bande,left);
        }
        if(j == (v.size()-1)){
            r = min(r,right);
        }
        if(l > 1e9){
            sa = ((r-l+1)%mod);
            ans = mod_add(ans,sa,mod);
            continue;
        }

        ll ele = v[j],prev = l;
        for(ll z = 1;;++z){
            if(ele < prev){ele *= v[j];continue;}
            ll len = (min(r+1,ele)-prev);
            ll sa2 = mod_mul(z-1,len,mod);
            sa = mod_add(sa,sa2,mod);

            if(ele > r){
                break;
            }
            prev = ele;
            ele = min((ll)1e18,ele*v[j]);
            // ele *= v[j];
        }
        ans = mod_add(ans,sa,mod);
    }

    cout<<ans<<endl;
    return;
}

vector<vector<ll>> v;
ll n;
map<ll, pair<ll,ll>> mp;
ll func_gx(ll x, ll fx){
    ll ans = 0, cur = 1;
    while ((LLONG_MAX / cur >= fx) && (cur * fx <= x)){
        ans++,cur *= fx;
    }
    return ans;
}

void precompute(){
    for(ll i = 2;i<60;++i){
        ll l = 1ll << i, r = (1ll << (i + 1)) - 1, fx = i;
        ll x = func_gx(l, fx), y = func_gx(r, fx);
        if (x == y){
            mp[l] = {r, x};
        }else{
            ll low = l, high = r, mid, v = l;
            while (low <= high){
                mid = (low+high)/2;
                if(func_gx(mid, fx) == x){
                    v = mid,low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
            mp[l] = {v, x};
            mp[v + 1] = {r, y};
        }
    }
}

void solve(){
    ll l,r;cin>>l>>r;
    ll ans = 0;
    while(l <= r){
        auto it = mp.upper_bound(l);
        --it;
        ll ele = min(it->second.first,r),val = it->second.second;
        ll sa = mod_mul(val,(ele-l+1),mod);
        ans = mod_add(ans,sa,mod);
        l = ele+1;
    }    
    ans %= mod;
    cout<<ans<<endl;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   precompute();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
   /*
    v.assign(150,vector<ll> (3,0));

    for(ll i = 2;i<60;++i){
        ll l = (1<<i),r = (1<<(i+1));
        ll gl = -1,x = l;
		while(x > 0) {
			x /= i;
			gl++;
		}

        ll gr = -1;
		x = r;
		while(x > 0) {
			x /= i;
			gr++;
		}
        // auto func = [&](ll x) -> ll {
        //     ll gl = -1;
        //     while(x>0){
        //         x /= i;++gl;
        //     }
        //     return gl;
        // };

        // ll gl = func(l);
        // ll gr = func(r);

        if(gl == gr){
            v[n++] = {l,r,gl};
        }else{
            x = 1;
            forj(gr){
                x *= i;
            }

            // assert(l<x and x<=r);
            if(l<x and x<=r){
                v[n++] = {l,x,gl};
                if(x < r){v[n++] = {x,r,gr};}
            }
        }

    }
*/
    // cout<<"HI\n";return 0;
    
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