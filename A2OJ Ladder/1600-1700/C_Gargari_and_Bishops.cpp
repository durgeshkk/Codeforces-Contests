/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

/*
If a cell attacked by bishop Gargari gets x dollars
Get Max. amt of money

Need to precompute for each cells the value I'll get if I place the bishop at 
cell (i,j)

1. Calculate Value of Top-Right type Diagonal,by using BFS & array of size 2*n-1
==> (i,j) will represent cell (i+j+1) on this array{top_right}

2. Calculate Value of Top-Left type Diagonal,by using BFS & array of size 2*n-1
==> (i,j) will represent cell (n+i-j) on this array{top_left}

3. Value for placing 1st bishop at (i,j) will be sum :
arr1[i+j+1]+arr2[n+i-j]-v[i][j] ; since the value v[i][j] is calculated twice

4. For placing 2nd bishop there will be an issue :
    -> Overlapping with the 1st bishop
        -> 2nd bishop is kept on the diagonal of 1st bishop itself
        -> 2nd bishop is kept s.t. it overlaps with 1st bishop on 2 cells
        -> 2nd bishop is kept s.t. it overlaps with 1st bishop on 0 cells

// --------
*** *** *** *** ***

But no tentions of this : Q has 1 V.V.IMP thing : 
"  Gargari wants to place two bishops on the chessboard in such 
    a way that there is no cell that is attacked by both of them. "

So place Bishop 1 at (i+j)&1 and Bishop 2 at (i+j)%2==0

*** *** *** *** ***
                                                            -------- //

*/

ll n;vector<vector<ll>> v,vis;
vector<ll> top_right,top_left;

bool isSafe(ll i,ll j){
    if(i >= n || j>=n || i<0 || j<0){return false;}return true;
}

void bfs(ll f){
    queue<pair<ll,ll>> q;
    if(f == 0){
        q.push({0,0});
        vis[0][0] = 1;
    }else{
        q.push({0,n-1});
        vis[0][n-1] = 1;
    }

    ll cnt = 1;
    while(!q.empty()){
        ll sz = q.size();
        ll sm = 0;
        while(sz--){
            auto p = q.front();q.pop();
            ll i = p.first,j = p.second;

            if(f == 0){
                // Push Right
                if(isSafe(i,j+1) and !vis[i][j+1]){
                    q.push({i,j+1});
                    vis[i][j+1] = 1;
                }
            }else{
                // Push Left
                if(isSafe(i,j-1) and !vis[i][j-1]){
                    q.push({i,j-1});
                    vis[i][j-1] = 1;
                }
            }

            // Down cells 
            if(isSafe(i+1,j) and !vis[i+1][j]){
                q.push({i+1,j});
                vis[i+1][j] = 1;
            }
            sm += v[i][j];
        }
        if(f == 0){
            top_right[cnt] = sm;
        }else{
            top_left[cnt] = sm;
        }
        ++cnt;//next level
    }
}

void solve()
{
 
    cin>>n;
    v.assign(n,vector<ll>(n,0));
    vis.assign(n,vector<ll>(n,0));
    top_right.assign(2*n+1,0);top_left.assign(2*n+1,0);
    for(ll i=0;i<n;i++){forj(n){cin>>v[i][j];}}

    bfs(0);
    vis.clear();
    vis.assign(n,vector<ll>(n,0));
    bfs(1);
    
    // show(top_right);
    // show(top_left);

    ll even_ans = 0,odd_ans = 0;
    pair<ll,ll> o={0,0} ,e = {0,0};
    for(ll i = 0;i<n;++i){
        forj(n){
            ll smallans = top_right[i+j+1]+top_left[n+i-j]-v[i][j];
            if((i+j) & 1){
                // Odd_ans
                if(smallans > odd_ans){
                    odd_ans = smallans;
                    o = {i,j};
                }
            }else{
                if(smallans > even_ans){
                    even_ans = smallans;
                    e = {i,j};
                }
            }
        }
    }

    if(o == e){
        o = {0,1};
    }
    cout<<odd_ans+even_ans<<endl;
    cout<<e.first+1<<" "<<e.second+1<<" "<<o.first+1<<" "<<o.second+1<<endl;
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}