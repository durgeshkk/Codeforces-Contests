#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n,m;
    cin>>n>>m;
    ll k;cin>>k;

    vector<ll> v(k);
    enter(v);

    sort(v.begin(),v.end(),greater<ll> ());
    ll ans = n*m;
    if(v[0] >= ans){
        cout<<"Yes\n";
        return;
    }


/*
    ll color = 0;
    ll f = 0;
    for(ll i=0;i<k;i++){
        ll val = (v[i]/(m));
        if(val > 1){
            if(val & 1){
                f = 1;
            }
            color += val;
        }
    }
*/
    if((n & 1) and (m & 1)){
        ll color = 0;
        ll f = 0;
        for(ll i=0;i<k;i++){
            ll val = (v[i]/(m));
            if(val > 1){
                if(val >= 3){
                    f = 1;
                }
                color += val;
            }
        }

        if(color >= n and f == 1){
            cout<<"Yes\n";
            return;
        }

        color = 0;
        f = 0;
        for(ll i=0;i<k;i++){
            ll val = (v[i]/(n));
            if(val > 1){
                if(val >= 3){
                    f = 1;
                }
                color += val;
            }
        }

        if(color >= m and f == 1){
            cout<<"Yes\n";
            return;
        }
        else{
            cout<<"No\n";
        }
        return;
    }
    else if(n%2 == 0 and m%2 == 0){
        ll color = 0;
        for(ll i=0;i<k;i++){
            ll val = (v[i]/(m));
            if(val > 1){
                color += val;
            }
        }

        if(color >= n){
            cout<<"Yes\n";
            return;
        }

        color = 0;
        for(ll i=0;i<k;i++){
            ll val = (v[i]/(n));
            if(val > 1){
                color += val;
            }
        }

        if(color >= m){
            cout<<"Yes\n";
            return;
        }
        cout<<"No\n";
    }
    else{
        // n is always even & m is odd..
        if(n & 1){
            swap(n,m);
        }

        ll color = 0;
        ll f = 0;
        for(ll i=0;i<k;++i){
            ll val = (v[i]/(m));
            if(val > 1){
                color += val;
            }
        }

        if(color >= n){
            cout<<"Yes\n";
            return;
        }          

        color = 0;
        f = 0;
        for(ll i=0;i<k;i++){
            ll val = (v[i]/(n));
            if(val > 1){
                if(val >= 3){
                    f = 1;
                }
                color += val;
            }
        }

        if(color >= m and f == 1){
            cout<<"Yes\n";
            return;
        } 
        cout<<"No\n";
    }
// */
/*
    ll a = min(n,m);
    ll b = max(n,m);
    m = a;
    n = b;

    if(n & 1){
        swap(n,m);
    }

    ll color = 0;
    ll f = 0;
    for(ll i=0;i<k;++i){
        ll val = (v[i]/(m));
        if(val > 1){
            color += val;
        }
    }

    if(color >= n){
        cout<<"Yes\n";
    }
    else{
        if(m & 1){
            ll color = 0;
            ll f = 0;
            for(ll i=0;i<k;i++){
                ll val = (v[i]/(n));
                if(val > 1){
                    if(val & 1){
                        f = 1;
                    }
                    color += val;
                }
            }

            if(color >= m and f == 1){
                cout<<"Yes\n";
                return;
            }
            cout<<"No\n";
        }
        else{
            ll z = 0;
            for(ll i=0;i<k;++i){
                ll val = (v[i]/(n));
                if(val > 1){
                    z += val;
                }
            }

            if(z >= m){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
    */
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