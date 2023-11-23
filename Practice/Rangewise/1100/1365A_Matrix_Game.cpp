#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
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
 
void solve()
{
 
    int n,m;
    cin>>n>>m;
/* GOOD LOGIC : 
    ll arr[n][m];
    set<ll> row,col;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];

            if(arr[i][j] == 1){
                row.insert(i);
                col.insert(j);
            }
        }
    }

    if((col.size() == m) || (row.size() == n)){
        cout<<"Vivek\n";
        return;
    }

    if(n < m){
        ll ans = n - row.size();
        if(ans%2){
            cout<<"Ashish\n";
        }   
        else{
            cout<<"Vivek\n";
        }
    }
    else if(m < n){
        ll ans = m - col.size();
        if(ans%2){
            cout<<"Ashish\n";
        }   
        else{
            cout<<"Vivek\n";
        }
    }
    else{
        ll ans = n - max(col.size(),row.size());
        if(ans%2){
            cout<<"Ashish\n";
        }
        else{
            cout<<"Vivek\n";
        }
    }
*/
// BRUTE FORCE :
    int a[n][m];

    memset(a,0,sizeof(a));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int k=0;
            cin>>k;
            if(k == 1){
                for(ll x=0;x<m;x++){
                    a[i][x] = 1;
                }
                for(ll x=0;x<n;x++){
                    a[x][j] = 1;
                }
            }
        }
    }

    int turn = 0;
    int f = 0;
    while(1){
        f = 0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(a[i][j] == 0){
                    turn++;
                    f = 1;
                    for(ll x=0;x<m;x++){
                        a[i][x] = 1;
                    }
                    for(ll x=0;x<n;x++){
                        a[x][j] = 1;
                    }
                    break;
                }
            }

            if(f == 1){
                break;
            }
        }
        if(f == 0){
            break;
        }
    }
    if(turn%2){
        cout<<"Ashish\n";
    }
    else{
        cout<<"Vivek\n";
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}