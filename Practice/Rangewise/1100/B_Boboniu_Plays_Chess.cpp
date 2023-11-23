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
 
    ll n,m;
    cin>>n>>m;
    ll r,c;
    cin>>r>>c;

    // bool vis[n][m] = {false};
    bool vis[n][m];
    
    // ll arr[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;i<m;j++){
            vis[i][j]= false;
        }
    }
/*
    for(ll i=0;i<n;i++){
        for(ll j=0;i<m;j++){
            // vis[i][j]= false;
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }*/

    ll j = c,i = r;
    while(j >= 0){
        vis[r][j] = true;
        cout<<r<<" "<<j<<endl;
        j--;
    }

    for(ll k = 0;k<n;k++){
        if(vis[i][k] == true){
            continue;
        }
        else{
            vis[i][k] = true;
            cout<<i<<" "<<k<<endl;
        }
    }



    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}