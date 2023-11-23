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

void solve()
{
 
    ll n;cin>>n;
    vector<vector<ll>> v(n,vector<ll> (n,0));
 
    ll ele = 1;

    // Front work done
    forj(n){
        if(j & 1){
            // Reverse time
            if(n & 1){
                for(ll i = n-2;i>=0;i-=2){
                    v[i][j] = ele;
                    ++ele;
                }
            }else{
                for(ll i = n-1;i>=0;i-=2){
                    v[i][j] = ele;
                    ++ele;
                }
            }
        }else{
            for(ll i=0;i<n;i+=2){
                v[i][j] = ele;++ele;
            }
        }
    }

    // for(ll i=0;i<n;i++){
    //         forj(n){
    //             cout<<v[i][j]<<" ";
    //         }cout<<endl;
    //     }

    //     cout<<"-----\n";
    // return;

    // Back work
    if(n & 1){
        for(ll j = n-1;j>=0;--j){
            if(j & 1){
                for(ll i = 0;i<n;i+=2){
                    v[i][j] = ele;++ele;
                } 
            }else{
                for(ll i = n-2;i>=0;i-=2){
                    v[i][j] = ele;++ele;
                }
            }
        }
    }else{
        for(ll j = n-1;j>=0;--j){
            if(j & 1){
                for(ll i = 0;i<n;i+=2){
                    v[i][j] = ele;++ele;
                } 
            }else{
                for(ll i = n-1;i>=0;i-=2){
                    v[i][j] = ele;++ele;
                }
            }
        }
    }

        /*
        for(ll j = n-1;j>=0;--j){
            if(j & 1){
                for(ll i = 0;i<n;i+=2){
                    v[i][j] = ele;++ele;
                }
            }else{
                for(ll i = n-2;i>=0;i-=2){
                    v[i][j] = ele;++ele;
                }
            }
        }*/
        /*
        // for(ll i=0;i<n;i++){
        //     forj(n){
        //         cout<<v[i][j]<<" ";
        //     }cout<<endl;
        // }
        // return;

        // Traverse odd cols & then even rows
        for(ll i=n-2;i>=0;i-=2){
            for(ll j = n-1;j>=0;j-=2){
                ll ele = *s.begin();
                s.erase(s.find(ele));
                v[i][j] = ele;
                if(s.find(ele+1) == s.end()){
                    s.erase(s.find(ele+2));
                    v[i+1][j-1] = ele+2;
                }else{
                    s.erase(s.find(ele+1));
                    v[i+1][j-1] = ele+1;
                }
            }
        }*/

        for(ll i=0;i<n;i++){
            forj(n){
                cout<<v[i][j]<<" ";
            }cout<<endl;
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