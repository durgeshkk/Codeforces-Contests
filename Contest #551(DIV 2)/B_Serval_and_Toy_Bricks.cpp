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

void disp(ll arr[100][100],ll n,ll m){
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
     
void solve(){
 
    ll n;
    cin>>n;
    ll m,h;
    cin>>m>>h;

    vector<ll> r(m);
    enter(r);

    vector<ll> c(n);
    enter(c);
 
    ll arr[n+1][m+1];
    ll vis[n][m];

    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;++j){
            cin>>arr[i][j];
            vis[i][j] = 0;
        }
    }

    // show(r);
    // show(c);

    for(ll i=0;i<m;i++){
        arr[n][i] = r[i];
    }

    for(ll j = 0;j<n;++j){
        arr[j][m] = c[j];
    }
    arr[n][m] = -1;
/*
    for(ll i = 0;i<n+1;++i){
        for(ll j = 0;j<m+1;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    */


    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;++j){
            if(arr[i][j] == 1){
                arr[i][j] = min(arr[i][m],arr[n][j]);
                // if(arr[i][m] == arr[n][j]){
                //     vis[i][j] = 1;
                //     arr[i][j] = arr[i][m];
                //     arr[i][m] = LLONG_MAX;
                //     arr[n][j] = LLONG_MAX;
                // }
            }
        }
    }

/*
    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;++j){
            if(arr[i][j] == 1){
                ll val = arr[i][m];
                ll val2 = arr[n][j];

                if(val == LLONG_MAX and val2 == LLONG_MAX){
                    continue;
                }

                if(val > val2){
                    arr[i][j] = val2;
                    arr[n][j] = LLONG_MAX;
                }else if(val == val2){
                    arr[i][j] = val2;
                    arr[n][j] = LLONG_MAX;
                    arr[i][m] = LLONG_MAX;
                }else{
                    arr[i][j] = val;
                    arr[i][m] = LLONG_MAX;
                }

                
            }
        }
    }
*/
/*
    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;++j){
            if(arr[i][j] == 1 and vis[i][j] == 0){
                vis[i][j] = 1;
                if(arr[i][m] != -1){
                    arr[i][j] = arr[i][m];
                    arr[i][m] = -1;
                }
                else if(arr[n][j] != -1){
                    arr[i][j] = arr[n][j];
                    arr[n][j] = -1;
                }
            }
        }
    }
*/

/*
    disp(arr,n,m);

    multiset<ll> mr,mc;
    map<ll,set<ll>> mpr,mpc;

    for(ll i=0;i<n;i++){
        mc.insert(c[i]);
        mpc[c[i]].insert(i);
    }




    map<ll,ll> mp;
    for(ll i=0;i<m;i++){
        ll val = r[i];
        if(val == 0){
            continue;
        }

        if(mc.find(val) == mc.end()){
            mp[i] = val;
        }else{
            set<ll> &s = mpc[val];
            ll er = -1;
            for(auto it:s){
                if((arr[it][i] == 1) and (vis[it][i] == 0)){
                    arr[it][i] = val;
                    (vis[it][i] == 1);
                    er = it;
                    break;
                }
            }

            s.erase(s.find(er));
            if(s.empty()){
                mpc.erase(mpc.find(val));
            }
        }
    }
 

    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            if(mp.find(j) != mp.end()){
                if((vis[j][i] == 0) and (arr[j][i]==1)){
                    (vis[j][i] == 1);
                    (arr[j][i] == mp[j]);
                    mp.erase(mp.find(j));
                }
            }
        }
    }

    mp.clear();

    for(auto it:mc){
        set<ll> s = mpc[it];
        for(auto j:s){
            mp[j] = it;
        }
    }

    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            if(mp.find(i) != mp.end()){
                if((vis[i][j] == 0) and (arr[i][j]==1)){
                    (vis[i][j] == 1);
                    (arr[i][j] == mp[i]);
                    mp.erase(mp.find(i));
                }
            }
        }
    }

*/
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
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
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
//    cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}