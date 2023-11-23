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

void solve()
{
 
    ll n,m;
    cin>>n>>m;

    char arr[n][m];
 
    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;++j){
            cin>>arr[i][j];
        }
    }

    ll sg = 0,dk = 0;
    
    // for(ll i=0;i<n;i++){
    //     for(ll j = 0;j<m;++j){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;++j){
            // cout<<i<<" "<<j<<endl;
            if(arr[i][j] == '*'){
                ++sg;
                ll x1 = -1,x2 = -1,y1 = -1,y2 = -1;

                ll fl = 0;
                ll f = 0; 
                ll val = 0;

                // |_
                if(i > 0 && j>0){
                    val = 0;
                    if(arr[i][j-1] == '*'){
                        if((x1 != i && y1 != (j-1))||(x2 != i && y2 != (j-1))){
                            fl++;
                        }
                        ++val;
                    }

                    if(arr[i-1][j-1] == '*'){
                        if((x1 != i-1 && y1 != (j-1))||(x2 != i-1 && y2 != (j-1))){
                            fl++;
                        }
                        ++val;
                    }

                    if(val == 2){
                        ++f;
                        x1 = i,y1 = j-1;
                        x2 = i-1,y2 = j-1;
                    }
                }
                // cout<<fl<<endl;
                // | -
                if(i > 0 && j<m-1){
                    val = 0;
                    if(arr[i-1][j] == '*'){
                        if((x1 != i-1 && y1 != (j))||(x2 != i-1 && y2 != (j))){
                            fl++;
                        }
                        ++val;
                    }

                    if(arr[i-1][j+1] == '*'){
                        if((x1 != i-1 && y1 != (j+1))||(x2 != i-1 && y2 != (j+1))){
                            fl++;
                        }
                        ++val;
                    }

                    if(val == 2){
                        ++f;
                        x1 = i-1,y1 = j;
                        x2 = i-1,y2 = j+1;
                    }
                }
// cout<<fl<<endl;
                // _|
                if(j > 0 && i<n-1){
                    val = 0;
                    if(arr[i+1][j] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j))||(x2 != i+1 && y2 != (j))){
                            fl++;
                        }
                    }

                    if(arr[i+1][j-1] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j-1))||(x2 != i+1 && y2 != (j-1))){
                            fl++;   
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i+1,y1 = j;
                        x2 = i+1,y2 = j-1;                        
                    }
                }
// cout<<fl<<endl;
                // 4th : -|
                if(i<n-1 && j<m-1){
                    val = 0;
                    if(arr[i+1][j+1] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j+1))||(x2 != i+1 && y2 != (j+1))){
                            fl++;
                        }
                    }

                    if(arr[i][j+1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j+1))||(x2 != i && y2 != (j+1))){
                            fl++;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i+1,y1 = j+1;
                        x2 = i,y2 = j+1;
                    }
                }
// cout<<fl<<endl;
// cout<<f<<endl;
                // 5th :
                if(i > 0 && j<m-1){
                    val = 0;
                    if(arr[i-1][j+1] == '*'){

                        if((x1 != i-1 && y1 != (j+1))||(x2 != i-1 && y2 != (j+1))){
                            ++fl;
                        }
                        ++val;
                    }

                    if(arr[i][j+1] == '*'){
                        if((x1 != i && y1 != (j+1))||(x2 != i && y2 != (j+1))){
                            ++fl;
                        }
                        ++val;
                    }

                    if(val == 2){
                        ++f;
                        x1 = i-1,y1 = j+1;
                        x2 = i,y2 = j+1;
                    }
                }
// cout<<fl<<endl;
                // 6th :
                if(i > 0 && j>0){
                val = 0;
                    if(arr[i-1][j-1] == '*'){
                        ++val;
                        if((x1 != i-1 && y1 != (j-1))||(x2 != i-1 && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(arr[i-1][j] == '*'){
                        ++val;
                        if((x1 != i-1 && y1 != (j))||(x2 != i-1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i-1,y1 = j-1;
                        x2 = i-1,y2 = j;
                    }

                }
// cout<<fl<<endl;
                // 7th :
                if(j > 0 && i<n-1){
                    val = 0;
                    if(arr[i+1][j-1] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j-1))||(x2 != i+1 && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(arr[i][j-1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j-1))||(x2 != i && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i+1,y1 = j-1;
                        x2 = i,y2 = j-1;
                    }
                }
// cout<<fl<<endl;
                // 8th :
                if(i < n-1 && j<m-1){
                    val = 0;
                    if(arr[i+1][j+1] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j+1))||(x2 != i+1 && y2 != (j+1))){
                            ++fl;
                        }
                    }

                    if(arr[i+1][j] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j))||(x2 != i+1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i+1,y1 = j+1;
                        x2 = i+1,y2 = j;
                    }
                }
// cout<<fl<<endl;
                // 9th :
                if(i > 0 && j<m-1){
                    val = 0;
                    if(arr[i-1][j] == '*'){
                        ++val;
                        if((x1 != i-1 && y1 != (j))||(x2 != i-1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(arr[i][j+1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j+1))||(x2 != i && y2 != (j+1))){
                            ++fl;
                        }
                    }
                    if(val == 2){
                        ++f;
                        x1 = i-1,y1 = j;
                        x2 = i,y2 = j+1;
                    }

                }
// cout<<fl<<endl;

                // 10th :
                if(i < n-1 && j<m-1){
                    val = 0;
                    if(arr[i][j+1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j+1))||(x2 != i && y2 != (j+1))){
                            ++fl;
                        }
                    }

                    if(arr[i+1][j] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j))||(x2 != i+1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i,y1 = j+1;
                        x2 = i+1,y2 = j;
                    }
                }
// cout<<fl<<endl;
                // 11th :
                if(i < n-1 && j>0){
                    val = 0;
                    if(arr[i][j-1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j-1))||(x2 != i && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(arr[i+1][j] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j))||(x2 != i+1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i,y1 = j-1;
                        x2 = i+1,y2 = j;
                    }
                }
// cout<<"HI"<<fl<<endl;

                // 12th :
                if(i >0 && j>0){
                    val = 0;
                    if(arr[i][j-1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j-1))||(x2 != i && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(arr[i-1][j] == '*'){
                        ++val;
                        if((x1 != i-1 && y1 != (j))||(x2 != i-1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i,y1 = j-1;
                        x2 = i-1,y2 = j;
                    }
                }





                if(f != 1){
                    // cout<<i<<" "<<j<<endl;
                    // cout<<"HI\n";
                    dk = 1;
                    // cout<<"NO\n";
                    // return;
                }

                fl = 0;


                ll stars = 0;

                if(i > 0 && j>0){
                    if(arr[i][j] == '*'){
                        stars++;
                    }

                    if(arr[i-1][j-1] == '*' && i > 0 && j > 0){
                        stars++;
                    }

                    if(arr[i-1][j] == '*' && i > 0){
                        stars++;
                    }

                    if(arr[i+1][j] == '*' && i < n-1){
                        stars++;
                    }


                    if(arr[i+1][j+1] == '*' && j < m-1 && i < n-1){
                        stars++;
                    }

                    if(arr[i-1][j+1] == '*' && j < m-1 && i > 0){
                        stars++;
                    }

                    if(arr[i+1][j-1] == '*' && j > 0 && i < n-1){
                        stars++;
                    }

                    if(arr[i][j-1] == '*' && j > 0){
                        stars++;
                    }

                    if(arr[i][j+1] == '*' && j < m-1){
                        stars++;
                    }

                    if(stars != 3){
                        // cout<<stars<<" ";
                        // cout<<i<<" "<<j<<" "<<dk<<endl;
                        dk = 1;
                    }

                }

/*
                // |_
                if(i > 0 && j>0){
                    if(arr[i][j-1] == '*'){
                        if((x1 != i && y1 != (j-1))&&(x2 != i && y2 != (j-1))){
                            fl++;
                        }
                    }

                    if(arr[i-1][j-1] == '*'){
                        if((x1 != i-1 && y1 != (j-1))&&(x2 != i-1 && y2 != (j-1))){
                            fl++;
                        }
                    }
                }
                // cout<<fl<<endl;
                // | -
                if(i > 0 && j<m-1){
                    if(arr[i-1][j] == '*'){
                        if((x1 != i-1 && y1 != (j))&&(x2 != i-1 && y2 != (j))){
                            fl++;
                        }
                    }

                    if(arr[i-1][j+1] == '*'){
                        if((x1 != i-1 && y1 != (j+1))&&(x2 != i-1 && y2 != (j+1))){
                            fl++;
                        }
                    }
                }
// cout<<fl<<endl;
                // _|
                if(j > 0 && i<n-1){
                    if(arr[i+1][j] == '*'){
                        if((x1 != i+1 && y1 != (j))&&(x2 != i+1 && y2 != (j))){
                            fl++;
                        }
                    }

                    if(arr[i+1][j-1] == '*'){

                        if(i == 0 && j == 1){
                            cout<<"HIdad\n";
                        }
                        
                        if((x1 != i+1 && y1 != (j-1))&&(x2 != i+1 && y2 != (j-1))){
                            fl++;   
                        }
                    }

                    // if(i == 0 && j == 1){
                    //     cout<<x1<<" "<<y1<<endl;
                    //     cout<<x2<<" "<<y2<<endl;
                    //     cout<<fl<<endl;
                    // }
                }
// cout<<fl<<endl;
                // 4th : -|
                if(i<n-1 && j<m-1){
                    val = 0;
                    if(arr[i+1][j+1] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j+1))&&(x2 != i+1 && y2 != (j+1))){
                            fl++;
                        }
                    }

                    if(arr[i][j+1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j+1))&&(x2 != i && y2 != (j+1))){
                            fl++;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i+1,y1 = j+1;
                        x2 = i,y2 = j+1;
                    }
                }
// cout<<fl<<endl;
// cout<<f<<endl;
                // 5th :
                if(i > 0 && j<m-1){
                    val = 0;
                    if(arr[i-1][j+1] == '*'){

                        if((x1 != i-1 && y1 != (j+1))&&(x2 != i-1 && y2 != (j+1))){
                            ++fl;
                        }
                        ++val;
                    }

                    if(arr[i][j+1] == '*'){
                        if((x1 != i && y1 != (j+1))&&(x2 != i && y2 != (j+1))){
                            ++fl;
                        }
                        ++val;
                    }

                    if(val == 2){
                        ++f;
                        x1 = i-1,y1 = j+1;
                        x2 = i,y2 = j+1;
                    }
                }
// cout<<fl<<endl;
                // 6th :
                if(i > 0 && j>0){
                val = 0;
                    if(arr[i-1][j-1] == '*'){
                        ++val;
                        if((x1 != i-1 && y1 != (j-1))&&(x2 != i-1 && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(arr[i-1][j] == '*'){
                        ++val;
                        if((x1 != i-1 && y1 != (j))&&(x2 != i-1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i-1,y1 = j-1;
                        x2 = i-1,y2 = j;
                    }

                }
// cout<<fl<<endl;
                // 7th :
                if(j > 0 && i<n-1){
                    val = 0;
                    if(arr[i+1][j-1] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j-1))&&(x2 != i+1 && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(arr[i][j-1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j-1))&&(x2 != i && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i+1,y1 = j-1;
                        x2 = i,y2 = j-1;
                    }
                }
// cout<<fl<<endl;
                // 8th :
                if(i < n-1 && j<m-1){
                    val = 0;
                    if(arr[i+1][j+1] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j+1))&&(x2 != i+1 && y2 != (j+1))){
                            ++fl;
                        }
                    }

                    if(arr[i+1][j] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j))&&(x2 != i+1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i+1,y1 = j+1;
                        x2 = i+1,y2 = j;
                    }
                }
// cout<<fl<<endl;
                // 9th :
                if(i > 0 && j<m-1){
                    val = 0;
                    if(arr[i-1][j] == '*'){
                        ++val;
                        if((x1 != i-1 && y1 != (j))&&(x2 != i-1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(arr[i][j+1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j+1))&&(x2 != i && y2 != (j+1))){
                            ++fl;
                        }
                    }
                    if(val == 2){
                        ++f;
                        x1 = i-1,y1 = j;
                        x2 = i,y2 = j+1;
                    }

                }
// cout<<fl<<endl;

                // 10th :
                if(i < n-1 && j<m-1){
                    val = 0;
                    if(arr[i][j+1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j+1))&&(x2 != i && y2 != (j+1))){
                            ++fl;
                        }
                    }

                    if(arr[i+1][j] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j))&&(x2 != i+1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i,y1 = j+1;
                        x2 = i+1,y2 = j;
                    }
                }
// cout<<fl<<endl;
                // 11th :
                if(i < n-1 && j>0){
                    val = 0;
                    if(arr[i][j-1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j-1))&&(x2 != i && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(arr[i+1][j] == '*'){
                        ++val;
                        if((x1 != i+1 && y1 != (j))&&(x2 != i+1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i,y1 = j-1;
                        x2 = i+1,y2 = j;
                    }
                }
// cout<<"HI"<<fl<<endl;

                // 12th :
                if(i >0 && j>0){
                    val = 0;
                    if(arr[i][j-1] == '*'){
                        ++val;
                        if((x1 != i && y1 != (j-1))&&(x2 != i && y2 != (j-1))){
                            ++fl;
                        }
                    }

                    if(arr[i-1][j] == '*'){
                        ++val;
                        if((x1 != i-1 && y1 != (j))&&(x2 != i-1 && y2 != (j))){
                            ++fl;
                        }
                    }

                    if(val == 2){
                        ++f;
                        x1 = i,y1 = j-1;
                        x2 = i-1,y2 = j;
                    }
                }

                if((fl != 0)){
                    // cout<<f<<" "<<fl<<endl;
                    // cout<<i<<" "<<j<<endl;
                    // cout<<x1<<" "<<y1<<endl;
                    // cout<<x2<<" "<<y2<<endl;
                    // cout<<fl<<" "<<f<<endl;
                    // cout<<"NO\n";
                    dk = 1;
                    // return;
                }*/

                // cout<<"--\n";
                // cout<<i<<" "<<j<<endl;
                // cout<<x1<<" "<<y1<<endl;
                // cout<<x2<<" "<<y2<<endl;
                // cout<<f<<" "<<fl<<endl;
                // cout<<"--\n";
            }
        
            // cout<<"---\n";
        }
    }

    if(dk  == 1){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";


    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
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