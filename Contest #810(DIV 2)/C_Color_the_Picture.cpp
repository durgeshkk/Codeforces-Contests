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

bool ak(ll n,ll m,ll k,set<ll> &s){
    ll f = false;
    ll val  = 0;
    ll dk = m/2;
    for(auto it:s){
        if(it/n >= 2){
            val++;
            if(it/n >= 3){
                f = true;
            }
        }
    }

    if((m & 1)){
        if(val >= dk && f == true){
            return true;
        }
        return false;
    }

    if(val >= dk){
        return true;
    }
    return false;
}


void solve()
{
 
    ll n,m,k;
    cin>>n>>m>>k;

    // ll a = n,b = m;
    // n = max(a,b);
    // m = min(a,b);

    set<ll> s;
    for(ll i = 0;i<k;++i){
        ll ak;
        cin>>ak;
        s.insert(ak);
    }

    // bool b = ak(m,n,k,s);
    // cout<<b<<endl;

    if(ak(n,m,k,s) || ak(m,n,k,s)){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }

/*
    ll space = n*m;
    ll mx = *s.rbegin();
    // if((n & 1) && (m & 1)){
        bool f = true;
        ll dk = (m/2);
        ll curr = 0;
        ll z = (2*n);
        for(auto it:s){
            ll val = it/z;
            if(val >= 1){
                curr += val;
            }
        }

        ll tu = ((mx)/(3*n));
        if(n & 1){
            f = false;
        }

        if(tu >= 1){
            f = true;
        }

        if(f == true && curr >= dk){
            cout<<"Yes\n";
            return;
        }


        f = false;
        dk = (n/2);
        curr = 0;
        z = (2*m);
        for(auto it:s){
            ll val = it/z;
            if(val >= 1){
                curr += val;
            }
        }

        if(m & 1){
            f = false;
        }

        tu = ((mx)/(3*m));
        if(tu >= 1){
            f = true;
        }

        if(f == true && curr >= dk){
            cout<<"Yes\n";
            return;
        }
        cout<<"No\n";
    // }
    */
    /*
    else if((m & 1)){

        ll dk = (n/2);
        ll curr = 0;
        ll z = (2*m);
        for(auto it:s){
            ll val = it/z;
            if(val >= 1){
                curr += val;
            }
        }

        if(curr >= dk){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    else{
        ll dk = (m/2);
        ll curr = 0;
        ll z = (2*n);
        for(auto it:s){
            ll val = it/z;
            if(val >= 1){
                curr += val;
            }
        }

        if(curr >= dk){
            cout<<"Yes\n";
            return;
        }

        dk = (n/2);
        curr = 0;
        z = (2*m);
        for(auto it:s){
            ll val = it/z;
            if(val >= 1){
                curr += val;
            }
        }

        if(curr >= dk){
            cout<<"Yes\n";
            return;
        }
        cout<<"No\n";
    }*/
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
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}