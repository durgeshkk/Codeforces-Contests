/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
vector<ll> adj[200004];
vector<ll> vis,tot_childs,flag_set,sm;
vector<pair<ll,ll>> range;
ll ans;
void lst_try(ll i,ll par){
    vis[i] = 1;
    
    ll flag = 0,smallans = 0;
    // if(i overlaps par){set flag to 1}
    for(auto it:adj[i]){
        if(!vis[it]){
            lst_try(it,i);
        }
    }

    if(par != -1){
        if(sm[i] >= range[i].first){
            flag_set[i] = 1;
            sm[i] = min(sm[i],range[i].second);
        }

        if(flag_set[i]){
            sm[par] += sm[i];
            if(sm[par] > range[par].second){
                sm[par] = range[par].second;
            }
        }else{
            sm[par] += range[i].second;
        }
    }else{
        if(sm[i] >= range[i].first){
            flag_set[i] = 1;
        }
    }
    return;
}


// ===>Faltu :{WRONG Interpretation ke awishkars!!}
/*
// Will return min. no. of operations
ll recur(ll i,ll par){
    vis[i] = 1;
    ll ans = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            ll val = recur(it,i);
            ans += val;
        }
    }

    if(par != -1){
        auto range_child = range[i].second;
        auto range_par = range[par].first;
        // cout<<i<<" -> "<<par<<" <->- ";
        // cout<<range_child<<" "<<range_par<<endl;
        if((range_child >= range_par)){
        }else{
            ++ans;
        }
    }

    // cout<<ans<<endl;
    // Small Calculations part with parent
    // cout<<i<<" -> "<<par<<" ";
    if(par == -1){
        // cout<<ans<<" -< "<<ans+1<<endl ;
        return ans+1;
    }
    else{
        // cout<<ans<<endl;
        return ans;
        // Check for overlapping range & calculate the ans
    }
}
*/
// Pass Range to childs & check if child range is gr8 in that of [l,r],
// -> If Fits update the [l,r] ==> to [l,gr8]
// -> else add 1 to ans & pass childs range to it's childs!!!

/*
void dfs(ll i,ll par,ll l,ll r){
    vis[i] = 1;

    // auto child_range = range[i];
    if(par != -1){
        flag_set[par] = 1;
        
        if(range[i].second >= l){
        //     l = range[i].first;
        // }else if(range[i].second >= r){
            r = range[i].second;
            --ans;
        }else{
            l = range[i].first;
            r = range[i].second;
            // ++ans;
        }
    }

    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it,i,l,r);
        }
    }
}
*/

void solve()
{
    ll n;cin>>n;
    // Precompute
    for(ll i=1;i<=n;i++){
        adj[i].clear();
    }
    vis.assign(n+1,0);
    range.assign(n+1,{0,0});
    flag_set.assign(n+1,0);
    sm.assign(n+1,0);

    // Here we go
    for(ll i=2;i<=n;i++){
        ll u;cin>>u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    for(ll i=1;i<=n;i++){
        ll a,b;cin>>a>>b;
        range[i] = {a,b};
    }

    // ll ans = recur(1,-1);
    // dfs(1,-1,range[1].first,range[1].second);
    // ans = lst_try(1,-1);
    // show(flag_set);

    lst_try(1,-1);
    ans = n;
    for(ll i = 1;i<=n;++i){
        if(flag_set[i] == 1){
            --ans;
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
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   return 0;
}