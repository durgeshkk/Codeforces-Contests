/*
    --> Author : daddy_dynamo
*/
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
#define no cout<<"NO\n";
#define yes cout<<"YES\n";
using namespace std;
ll mod = (ll)(1e9+7);
 

void solve()
{
    // cout<<"HI\n";
    ll n,m;cin>>n>>m;
    char arr[n+1][m+1];char v[n+1][m+1];

    for(ll i=0;i<=n;i++){
        for(ll j = 0;j<=m;++j){
            arr[i][j] = 'y';
            v[i][j] = 'y';
        }
    }

    for(ll i=1;i<=n;i++){
        for(ll j = 1;j<=m;++j){
            cin>>arr[i][j];
            if(arr[i][j] == 'X'){
                v[i][j] = 'n';
            }
        }
    }

    

    for(ll i=1;i<=n;i++){
        for(ll j = 1;j<=m;++j){

            if(arr[i][j-1] == 'X' and (arr[i-1][j] == 'X')){
                v[i][j] = 'N';
            }
            // else if(arr[i][j-1] == 'X' and (v[i-1][j] == 'N')){
            //     v[i][j] = 'N';
            // }
            // else if(v[i][j-1] == 'N' and (arr[i-1][j] == 'X')){
            //     v[i][j] = 'N';
            // }
            // else if(v[i][j-1] == 'N' and (v[i-1][j] == 'N')){
            //     v[i][j] = 'N';
            // }
            else{
                v[i][j] = 'y';
            }
        }
    }

    ll idx = 0;
    vector<ll> ans(m+1,0);
    for(ll j = 1;j<=m;++j){
        ll cnt = 0;
        for(ll i=1;i<=n;i++){
            if(v[i][j] == 'N'){
                idx = j-1;break;
            }
            else if(v[i][j] == 'n'){
                ++cnt;
            }
        }
        if(cnt == n){
            // No need to check for 'X' as they r always determinable & have only 1 ans
            idx = j;
            ans[j] = idx;
            continue;
        }
        ans[j] = (idx);
    }

    /*
    ordered_set col;
    for(ll j = 0;j<=m;++j){
        ll f = 1;
        for(ll i = 0;i<=n;++i){
            if((v[i][j] == 'n') and (arr[i][j] != 'X')){
                f = 0;
                break;
            }
        }
        if(f & 1){
        }else{
            col.insert(j);
        }
    }

    for(auto it:col){
        cout<<it<<" ";    
    }cout<<endl;*/
    // show(ans);
    ll q;cin>>q;
    for(ll i = 0;i<q;++i){
        ll l,r;cin>>l>>r;
        ll val = ans[r];
        if(val < l || val > r){
            yes;
        }else{
            no;
        }
        /*
        if(col.find(l) != col.end()){
            no;
            continue;
        }
        if(col.find(r) != col.end()){
            no;continue;
        }

        if(l == r){
            yes;continue;
        }
        col.insert(l);
        col.insert(r);
        ll idx1 = col.order_of_key(l);
        ll idx2 = col.order_of_key(r);
        col.erase(col.find(l));
        col.erase(col.find(r));
        if((idx2-idx1) == 1){
            yes;continue;
        }else{
            no;continue;
        }*/
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   solve();
   return 0;
}