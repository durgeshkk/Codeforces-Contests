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
 
    ll n,m;
    cin>>n>>m;

    ll b[n][m];

    ll a[n][m];
    ll c[n][m];

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>b[i][j];
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            a[i][j] = b[i][j];
            c[i][j] = b[i][j];
        }
    }
    
    for(ll i=0;i<n;i++){
        ll prev = a[i][m-1];

        for(ll j=(m-1);j>=0;j--){
            if(j == (m-1) && (a[i][j]== 0)){
                a[i][j] = 8000;
                prev = 8000;
            }

            if(a[i][j] == 0){
                a[i][j] = (prev-1);
                prev--; 
            }
            else{
                if(a[i][j] >= prev && (j!=(m-1))){
                    cout<<-1<<endl;
                    return;
                }
                prev = a[i][j];
            }
        }
    }

    for(ll j=0;j<m;j++){
        ll prev = c[n-1][j];

        for(ll i=(n-1);i>=0;i--){
            if(i == (n-1) && (c[i][j]== 0)){
                c[i][j] = 8000;
                prev = 8000;
            }

            if(c[i][j] == 0){
                c[i][j] = (prev-1);
                prev--; 
            }
            else{
                if(c[i][j] >= prev && (i!=(n-1))){
                    cout<<-1<<endl;
                    return;
                }
                prev = c[i][j];
            }
        }
    }

    ll sm = 0;
    for(ll i=0;i<n;i++){
        for(ll j=(m-1);j>=0;j--){
            b[i][j] = min(a[i][j],c[i][j]);
            sm+=b[i][j];
        }
    }
    cout<<sm<<endl;

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    ll t;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
   solve();
   return 0;
}