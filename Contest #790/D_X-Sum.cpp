#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll LCM(ll a,ll b){
   ll answer = (a*b)/__gcd(a,b);
   return answer;
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

    ll maxi = INT16_MIN;
    int arr[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j] > maxi){
                maxi = arr[i][j];
            }
        }
    }

    ll answer = 0;
    if(n == 1 || m == 1){
        cout<<maxi<<endl;
        return;
    }
    else{
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                ll st = arr[i][j];
                ll a = i - 1, b = j - 1;
                while (a >= 0 && b >= 0)
                {
                    st += arr[a][b];
                    a--;
                    b--;
                }
                a = i + 1, b = j + 1;
                while (a < n && b < m)
                {
                    st += arr[a][b];
                    a++;
                    b++;
                }
                a = i + 1, b = j - 1;
                while (a < n && b >= 0)
                {
                    st += arr[a][b];
                    a++;
                    b--;
                }
                a = i - 1, b = j + 1;
                while (a >= 0 && b < m)
                {
                    st += arr[a][b];
                    a--;
                    b++;
                }
                answer = max(answer,st);
            }

        }
    }
    cout<<answer<<endl;
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