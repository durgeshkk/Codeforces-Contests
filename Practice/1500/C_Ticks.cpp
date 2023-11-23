#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;




bool dfs(ll i,ll j,vector<vector<char>> &v,ll n,ll m,vector<vector<ll>> &vis,ll d){

    ll row=i,col = j;
    ll l = 0, r = 0;
    while(i>0 && j>0 && v[--i][--j] == '*'){
        ++l;
    }
    
    i = row,j = col;
    while(i>0 && j<m-1 && v[--i][++j] == '*'){
        ++r;
    }

    // cout<<l<<" "<<r<<endl;
    // cout<<d<<endl;
    if(l >= d && r >= d){
        i = row,j = col;
        vis[i][j] = 1;
        if(l == r){
            while(i>0 && j>0 && v[--i][--j] == '*'){
                vis[i][j] = 1;
            }

            i = row,j = col;
            while(i>0 && j<m-1 && v[--i][++j] == '*'){
                vis[i][j] = 1;
            }

            return true;
        }
        if(l > r){
            ll cnt = 0;
            while(i>0 && j>0 && v[--i][--j] == '*' && cnt < r){
                ++cnt;
                vis[i][j] = 1;
            }

            i = row,j = col;
            while(i>0 && j<m-1 && v[--i][++j] == '*'){
                vis[i][j] = 1;
            }
        }
        else{
            ll cnt = 0;
            while(i>0 && j>0 && v[--i][--j] == '*'){
                vis[i][j] = 1;
            }

            i = row,j = col;
            while(i>0 && j<m-1 && v[--i][++j] == '*' && cnt < l){
                ++cnt;
                vis[i][j] = 1;
            }
        }
        return true;
    }
    
    i = row,j = col;
    if(vis[i][j] == 1){
        return true;
    }
    return false;

/*
    if(v[i-1][j-1] == '*' && i>0 && j>0 && (!vis[i-1][j-1])){
        l = 1+dfs(i-1,j-1,v,n,m);
    }

    if(v[i-1][j+1] == '*' && i>0 && j<m-1 && (!vis[i-1][j+1])){
        r = 1+dfs(i-1,j+1,v,n,m);
    }
*/

}

void solve()
{
    ll n,m,d;
    cin>>n>>m>>d;

    vector<vector<ll>> vis(n,vector<ll> (m,0));

    // cout<<d<<endl;
    vector<vector<char>> v(n,vector<char> (m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    
    for(ll i = n-1;i>=0;--i){
        for(ll j = 0;j<m;++j){
            if(v[i][j] == '*'){
                // cout<<i<<" "<<j<<endl;
                bool b = dfs(i,j,v,n,m,vis,d);
                if(b == true){

                }
                else{
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin>>t;
   while(t--){
    solve();
   }
   return 0;
}
/*
5 6 2
......
.....*
*...*.
.*.*..
..*...

*/