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
using namespace std;
ll mod = (ll)(1e9+7);
 
ll a,b,c,k;
void print(ll a,ll b,ll c){
    cout<<a<<" + "<<b<<" = "<<c<<endl;
}

ll power(ll a){
    ll cntr = 0,s = 1;
    while(cntr != a){
        s *= 10;
        ++cntr;
    }
    return s;
}

ll mn(ll x){
    return power(x-1);
}

ll mx(ll x){
    return power(x)-1;
}

void solve()
{
 
    cin>>a>>b>>c>>k;
    ll flag = 0;
    if(c < max(a,b)){cout<<"-1\n";return;}
    vector<ll> tmp = {9,90,900,9000,90000,900000};

    ll mnb = mn(b),mxb = mx(b);
    ll mnc = mn(c),mxc = mx(c);

    for(ll i = mn(a);i<=mx(a);++i){
        ll low = mnc-i,r = mxc-i;
        low = max(low,mnb);
        r = min(r,mxb);

        if(low > r){continue;}
        ll range = r-low+1;
        if(range >= k){
            ll x = i,y = low+k-1;
            print(x,y,x+y);
            return;
        }else{
            k -= range;
        }
    }

    cout<<"-1\n";
    /*
    if(b > a){flag = 1;swap(a,b);}
    ll cntr = 0,s = 1;
    while(cntr != c){
        s *= 10;
        ++cntr;
    }
    ll e = s-1;
    s /= 10;

    cntr = 0;ll ok = 1;
    while(cntr != b){
        ok *= 10;
        ++cntr;
    }
    ll mn = ok/10;
    --ok;
    cout<<mn<<endl;
    

    for(ll i = s;i<=e;++i){
        if(a == b){
            // Get by / 2
            ll req = i/2;
            ll req2 = (i+1)/2;
            ll sm = (req-ok+1);
            k -= (sm*2);
            if(k <= 0){
                print(req,req2,i);
            }
        }else{
            // Get by providing b as max
            ll amin = (ok);
            k -= ok;
            if(k <= 0){
                if(flag){
                    // b is gr8
                    print(ok,i-ok,i);
                }else{
                    print(i-ok,ok,i);
                }
                return;
            }
        }
    }*/
    // cout<<s<<" "<<e<<endl;
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