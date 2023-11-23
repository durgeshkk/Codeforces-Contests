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
 
vector<vector<ll>> adj[200004];
map<pair<ll,ll>,ll> aj;
map<pair<ll,ll>,ll> bj;
vector<ll> vis,ans,vis2,prefa,prefb;
/*
void dfs(ll i,ll par,ll sma){
    vis[i] = 1;
    for(auto it:adj[i]){
        if(!vis[it]){
            sma = aj[{it,i}];
            prefa[it] = sma + prefa[i];
            dfs(it,i,sma);
        }
    }
    return;
}

void dfs2(ll i,ll par_i,ll sm){
    vis2[i] = 1;
    for(auto it:adj[i]){
        if(!vis2[it]){
            sm = bj[{it,i}];
            prefb[it] = prefb[i] + sm;
            dfs2(it,i,sm);
        }
    }
    return;
}

void recur(ll i,ll j,ll cnt){
    vis[i] = 1;
    vis2[j] = 1;

    // If prefa >= prefb
    if((prefa[i] >= prefb[j]) and (i != 1)){

        while(prefa[i] >= prefb[j]){
            if(i == j){
                if(prefa[i] >= prefb[j]){
                    ++cnt;
                }
                for(auto z:adj[j]){
                    if(!vis2[z]){
                        vis2[z] = 1;
                        j = z;break;
                    }
                }
                break;
            }
        
            ++cnt;
            for(auto z:adj[j]){
                if(!vis2[z]){
                    vis2[z] = 1;
                    j = z;break;
                }
            }
        }
    }
    // else

    for(auto it:adj[i]){
        if(!vis[it]){
            recur(it,j,cnt);
        }
    }

    ans[i] = cnt;
}
*/
void lst(ll i,ll sm,vector<ll> &v){

    ans[i] = lower_bound(v.begin(),v.end(),sm+1)-v.begin();

    for(auto it:adj[i]){
        if(v.empty()){
            v.push_back(it[2]);
        }else{
            v.push_back(v.back()+it[2]);
        }
        lst(it[0],sm+it[1],v);
        v.pop_back();
    }
}

void solve()
{
 
    ll n;cin>>n;
    // precompute
    aj.clear();bj.clear();
    vis.assign(n+1,0);vis2.assign(n+1,0);
    prefa.assign(n+1,0);prefb.assign(n+1,0);
    ans.assign(n+1,0);
    for(ll i=1;i<=n;i++){adj[i].clear();}

    // aj ke liye DFS chalao normal!!
    // bj ke liye use Queue to store upcmng values!!
    vector<ll> tmp(3);
    for(ll i=2;i<=n;i++){
        ll u;cin>>u;
        ll a,b;cin>>a>>b;
        tmp[0] = i;tmp[1] = a;tmp[2] = b;
        adj[u].push_back(tmp);
    }

    vector<ll> z;
    lst(1,0,z);

    for(ll i = 2;i<=n;++i){
        cout<<ans[i]<<" ";
    }cout<<endl;
    // show(ans);
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