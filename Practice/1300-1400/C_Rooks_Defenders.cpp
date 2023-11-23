#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#define ll long long int
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}
void solve()
{
 
    ll n;
    cin>>n;

    ll q;
    cin>>q;

    // ll arr[n][n];
    // ll vis[n][n] = {0};

    map<ll,ll> row,col;
/*
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<n;j++){
            vis[i][j] = 0;
        }
    }
*/

    ordered_set s1,s2;
    for(ll i=0;i<q;i++)
    {
        ll tt;
        cin>>tt;

        if(tt == 1)
        {
            ll x,y;
            cin>>x>>y;
            // cout<<x<<y<<endl;
            // x--,y--;
            row[x]++;
            col[y]++;

            if(row[x] == 1){
                s1.insert(x);
            }

            if(col[y] == 1){
                s2.insert(y);
            }
        }
/*
            for(ll j=0;j<n;j++){
                vis[x][j]++;
            }

            for(ll j=0;j<n;j++){
                vis[j][y]++;
            }
        }*/
        else if(tt == 2){
            ll x,y;
            cin>>x>>y;
            // cout<<x<<y<<endl;

            row[x]--;
            col[y]--;

            if(row[x] == 0){
                s1.erase(x);
            }

            if(col[y] == 0){
                s2.erase(y);
            }
/*
            x--,y--;

            for(ll j=0;j<n;j++){
                vis[x][j]--;
            }

            for(ll j=0;j<n;j++){
                vis[j][y]--;
            }*/
        }
        else{
            ll x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;

            if((s1.order_of_key(x2 + 1) - s1.order_of_key(x1) == x2 - x1 + 1) || (s2.order_of_key(y2 + 1) - s2.order_of_key(y1)) == y2 - y1 + 1){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }

            // cout<<x1<<y1<<x2<<y2<<endl;
/*
            x1--,y1--;
            x2--,y2--;

            ll f = 0;
            for(ll j=x1;j<=x2;j++){
                for(ll k=y1;k<=y2;k++){
                    if(vis[j][k]==0){
                        cout<<"No\n";
                        f = 1;
                        break;
                        // return;
                    }
                }

                if(f == 1){
                    break;
                }
            }

            if(f == 1){
                continue;
            }

            cout<<"Yes\n";*/
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll t=1;
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}