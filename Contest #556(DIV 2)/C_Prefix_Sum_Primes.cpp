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

ll sieve[4000001];
void createsieve(){
    ll ntlen = 400001;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == 1){
            for(ll j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
            }
        }
    }
}
 
vector<ll> prim;
void p(ll sm){
    for(ll i = 3;i<=sm;++i){
        if(sieve[i] == 1){
            prim.push_back(i);
        }
    }
}

void pb(vector<ll> &v, ll val, ll n){
    for(ll i = 0;i<n;++i){
        v.push_back(val);
    }
}

void solve()
{

    ll n;
    cin>>n;

    ll c1 = 0,c2 = 0, sm = 0;
    for(ll i=0;i<n;i++){
        ll a; cin>>a;
        sm += a;
        if(a == 1){
            ++c1;
        }else{
            ++c2;
        }
    }

    if(c2 == 0){
        for(ll i = 0;i<c1;++i){
            cout<<1<<" ";
        }cout<<endl;return;
    }

    if(c1 == 0){
        for(ll i = 0;i<c2;++i){
            cout<<2<<" ";
        }cout<<endl;return;
    }

    cout<<2<<" ";
    --c2;
    cout<<1<<" ";
    --c1;
    for(ll i = 0;i<c2;++i){
        cout<<2<<" ";    
    }
    
    for(ll i = 0;i<c1;++i){
        cout<<1<<" ";    
    }
    cout<<endl;
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
//    createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   ll i = 1;
   solve();
   return 0;
}
/*
    p(sm);

    vector<ll> ans;
    ll j = 0, prev = 2;
    while(j < prim.size()){
        ll diff = (prim[j]-prev);

        if(diff & 1){

            if(c1 == 0){
                ++j;continue;
            }

            ll req = diff/2;
            if(c2 >= req){
                c2 -= req;
                pb(ans,2,req);
                --c1;
                pb(ans,1,1);
                prev = prim[j];
            }else{
                ll mr = req-c2;
                mr *= 2;
                ++mr;

                if(c1 >= (mr)){
                    pb(ans,2,c2);
                    c2 = 0;

                    pb(ans,1,mr+1);
                    --c1;
                    c1 -= mr;
                    prev = prim[j];
                }else{
                    ++j;continue;
                }

            }
        }else{
            ll req = diff/2;

            if(c2 >= req){
                c2 -= req;
                pb(ans,2,req);
                prev = prim[j];
            }else{
                ll mr = req-c2;
                mr *= 2;

                if(c1 >= (mr)){
                    pb(ans,2,c2);
                    c2 = 0;

                    pb(ans,1,mr);
                    c1 -= mr;
                    prev = prim[j];
                }else{
                    ++j;continue;
                }
            }
        }
        ++j;
    }

    show(ans);*/
/*
ll sieve[400001];
void createsieve(ll sm){
    ll ntlen = sm;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == 1){
 
            for(ll j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
            }
        }
    }
}

vector<ll> prim;
void printPrime(ll n)
{
    for (ll i = 2; i <= n; i++) {
        if (sieve[i] == 1)
            prim.push_back(i);
    }
} 

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);

    map<ll,ll> mp;
    ll sm = 0;
    for(ll i=0;i<n;i++){
        sm += v[i];
        mp[v[i]]++;
    }
    
    if(mp[2] == 0){
        show(v);
        return;
    }

    printPrime(sm);

    vector<ll> num,occ;
    vector<ll> ans;
    ans.push_back(2);
    mp[2]--;

    ll j = 1,prev = 2;
    while(prim[j] <= sm){
        ll z = (prim[j]-prev);
        if(z == 1){
            if(mp[1] >= 0){
                mp[1]--;
                num.push_back(1);
                occ.push_back(1);
                // ans.push_back(1);
                prev = prim[j];
            }else{
                ++j;
                continue;
            }
        }else{
            if(z & 1){
                ll req = (z/2);

                if(mp[1] == 0){
                    ++j;continue;
                }

                if(mp[2] >= req){
                    mp[2] -= req;
                    // Push
                    num.push_back(2);
                    occ.push_back(req);

                    // p(ans,2,req);
                    prev = prim[j];
                    mp[1]--;
                    num.push_back(1);
                    occ.push_back(1);
                    // ans.push_back(1);
                }else{
                    ll lft = (req-mp[2]);
                    lft *= 2;
                    ++lft;
                    if(lft <= mp[1]){
                        mp[1] -= lft;
                        // Push
                        num.push_back(2);
                        occ.push_back(mp[2]);
                        // p(ans,2,mp[2]);
                        
                        num.push_back(1);
                        occ.push_back(lft);
                        // p(ans,1,lft);
                        
                        prev = prim[j];
                    }else{
                        ++j;continue;
                    }
                }

            }else{
                ll req = (z/2);
                if(mp[2] >= req){
                    mp[2] -= req;
                    // Push
                    num.push_back(2);
                    occ.push_back(req);
                    // p(ans,2,req);
                    prev = prim[j];
                }else{
                    ll lft = (req-mp[2]);
                    lft *= 2;
                    if(lft <= mp[1]){
                        mp[1] -= lft;
                        // Push
                        num.push_back(2);
                        occ.push_back(mp[2]);
                        // p(ans,2,mp[2]);
                        
                        num.push_back(1);
                        occ.push_back(lft);
                        // p(ans,1,lft);
                        prev = prim[j];
                        
                    }else{
                        ++j;continue;
                    }
                }
            }
        }

        ++j;
    }

    // show(num);
    // show(occ);

    for(ll i = 0;i<num.size();++i){
        ll val = occ[i];
        for(ll j = 0;j<val;++j){
            ans.push_back(num[i]);
        }
    }
    show(ans);
    return;
}

*/