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
 
void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}

ll n,m;
bool check(ll i,ll j){
    if(i < 0 || i >= n || j >=m || j < 0){return false;}
    else{return true;}
}

vector<vector<ll>> v;
ll ans,f;

void dfs(ll i,ll j,ll pos,ll neg){
    if(!check(i,j)){return;}

    if(i == (n-1) and j == (m-1)){
        if(v[i][j] == 1){++pos;}
        else{++neg;}

        if(pos == neg){
            f = 1;
        }
        return;
    }

    if(v[i][j] == 1){
        dfs(i+1,j,pos+1,neg);
        dfs(i,j+1,pos+1,neg);
    }else{
        dfs(i+1,j,pos,neg+1);
        dfs(i,j+1,pos,neg+1);
    }
    return;
}


void helper(vector<vector<ll>> &mn,vector<vector<ll>> &mx){
    if((n+m) %2 == 0){f = 0;return;}

    mn[0][0] = mx[0][0] = v[0][0];

    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            if(i > 0 and (j>0)){// Ye cell pe (i,j-1) or (i-1,j) se hi ayye honge
                mn[i][j] = (min(mn[i-1][j],mn[i][j-1])+v[i][j]);
                mx[i][j] = (max(mx[i-1][j],mx[i][j-1])+v[i][j]);
            }else if(i > 0){// Ye cell pe (i-1,j) se hi ayye honge
                mn[i][j] = ((mn[i-1][j])+v[i][j]);
                mx[i][j] = ((mx[i-1][j])+v[i][j]);
            }else if(j > 0){// Ye cell pe (i,j-1) se hi ayye honge
                mn[i][j] = ((mn[i][j-1])+v[i][j]);
                mx[i][j] = ((mx[i][j-1])+v[i][j]);
            }
        }
    }

    if(mn[n-1][m-1] <= 0 and mx[n-1][m-1] >= 0){
        f = 1;
    }else{
        f = 0;return;
    }
    
}


void solve()
{
 
    cin>>n>>m;
    f = 1;
    v.assign(n,vector<ll> (m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    // No. of 1's == No. of -1's
    // => Len should be even {n+m-1}%2 == 0 ==> n+m must be odd!!
    // Steps = {n+m-2} & initially at (0,0) so, {n+m-1}
    // If there are x +1 & x -1 ;and I replace 1 (+x -> -x) then sm will reduce 
    // by 2..
    // Let's consider 2 values, min & max from (1,1) -> (n,m)
    // If min = -6 & mx = +2 ==> It's always pssbl that I can choose 1 (-1->+1)path,
    // diff = 2-(-6) = 8,yane replace 4 (-1->+1) in a path aye honge min path aur max
    // path mein tb hi mn = -6 h aur mx = +2 h...
    // So, agar mein 4 -1 ko +1 se replace kr paa rha hu yane mein 3 -1->+1 kr hi 
    // sakta hu!!! {-6+2*(1) = 0},, Thus,0 path is pssbl

    // At (1,2) we can only have odd values{1+1+1 = 3,1+1-1=1,-1,-3}
    // At (1,3) it wil have even values only!! {4,2,0,-2,-4}
    // If on a grid I'm able to form 4 & -4 then I'm able to form all between even 
    // values of it... So it's only req to store some max. & min. values somewhere!
    
    // dfs(0,0,0,0);
    vector<vector<ll>> mn(n,vector<ll> (m,LLONG_MAX));
    vector<vector<ll>> mx(n,vector<ll> (m,LLONG_MIN));
    helper(mn,mx);
    /*
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<mn[i][j]<<" ";
        }cout<<endl;
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<mx[i][j]<<" ";
        }
    }*/
    yno(f);
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