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
 
    ll l = 1,h = (ll)1e6;
    while(l < h){
        ll mid = (l+h+1)/2;
        cout<<mid<<endl;
        fflush(stdout);

        string x;cin>>x;

        if(x == ">="){
            l = mid;
        }else{
            h = mid-1;
        }
    }
    cout<<"! "<<l<<endl;
    fflush(stdout);
    return;
}

void solve1(){

    ll n;cin>>n;
    ll prev = 0,f = 0;
    ll onetwo = 0;

    vector<ll> dynamo(n+1,0);
    for(ll i = 1;i<n;++i){
        ll l = 1,r=(i+1);
        cout<<"? "<<l<<" "<<r<<endl;
        fflush(stdout);
        ll ans;cin>>ans;
        if(f == 0){
            f = 1;onetwo = ans;
        }else{
            dynamo[r] = (ans-prev); 
        }
        prev = ans;
    }

    cout<<"? "<<2<<" "<<3<<endl;
    fflush(stdout);
    ll ans;cin>>ans;
    dynamo[2] = ans-dynamo[3];
    dynamo[1] = onetwo-dynamo[2];
    cout<<"! ";
    for(ll i = 1;i<=n;++i){
        cout<<dynamo[i]<<" ";
    }cout<<endl;
    // show(dynamo);
    fflush(stdout);
}

vector<ll> adj[100004];
vector<ll> vis;

void dfs(ll i){
    vis[i] = 1;

    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it);
        }
    }
    return;
}

void solve2(){
    ll n;cin>>n;vector<ll> v(n);enter(v);
    vis.assign(n+1,0);

    for(ll i = 0;i<n;++i){
        adj[i+1].push_back(v[i]);
        adj[v[i]].push_back(i+1);
    }

    ll dynamo = 0;
    for(ll i = 1;i<=n;++i){
        if(!vis[i]){
            ++dynamo;
            dfs(i);
        }
    }
    cout<<dynamo<<endl;
    return;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    solve();
//    solve1();
   solve2();
   return 0;
}