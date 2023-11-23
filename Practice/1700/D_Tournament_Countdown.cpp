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
ll mod = (ll)(1e18);
#define insert push_back  
void solve()
{
 
    ll n;cin>>n;
    ll parti = pow(2,n);
    vector<ll> winners;
    for(ll i = 1;i<=parti;i++){
        winners.insert(i);
    }

    while(winners.size() > 3){
        vector<ll> win;
        ll f = 0,a = 0,b = 0,c=0,d=0;
        for(auto it:winners){
            if(f == 0){
                a = it;
            }else if(f == 1){
                b = it;
            }else if(f == 2){
                c = it;
            }else{
                d = it;
                ll z;
                cout<<"? "<<a<<" "<<c<<endl;
                fflush(stdout);
                cin>>z;
                if(z == 0){
                    // Both equal; winners r (2 or 4)
                    cout<<"? "<<b<<" "<<d<<endl;
                    fflush(stdout);
                    cin>>z;
                    if(z == 1){
                        win.insert(b);
                    }else{
                        win.insert(d);
                    }
                }else if(z == 1){
                    // Winners r 1 or 4
                    cout<<"? "<<a<<" "<<d<<endl;
                    fflush(stdout);
                    cin>>z;
                    if(z == 1){
                        win.insert(a);
                    }else{
                        win.insert(d);
                    }
                }else{
                    // Winners r 2 or 3
                    cout<<"? "<<b<<" "<<c<<endl;
                    fflush(stdout);
                    cin>>z;
                    if(z == 1){
                        win.insert(b);
                    }else{
                        win.insert(c);
                    }
                }
                // f = 0;
            }
            ++f;
            f %= 4;
        }

        winners.clear();
        winners = win;
    }

    ll ans = 0;
    ll a = winners[0];
    ll b = winners[1];
    cout<<"? "<<a<<" "<<b<<endl;
    fflush(stdout);
    ll z;cin>>z;
    if(z == 1){
        ans = a;
    }else{
        ans = b;
    }

    cout<<"! "<<ans<<endl;
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