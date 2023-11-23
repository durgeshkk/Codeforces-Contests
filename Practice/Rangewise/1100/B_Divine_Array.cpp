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
 /*
 LEARNING : 
 Check the question properly n ka constraint is too small so we can apply brute force till n
 & thereafter already we will reach max freq which will all be unique so can directly return
 the value of old updated array!!
 */
    ll n;
    cin>>n;
    // map<ll,ll> mp;
    int arr[n];

    for(ll i=0;i<n;i++){
       cin>>arr[i];
    }

// Will now store how the array looks after k steps
    int v[n+1][n];
    for(ll i = 0;i<n;i++){
        v[0][i] = arr[i];
    }

    for(int i=1;i<=n;i++){
        map<int,int> mp;

        for(int k=0;k<n;k++){
            mp[arr[k]]++;
        }

        for(int j=0;j<n;j++){
            arr[j] = mp[arr[j]];
            v[i][j] = arr[j];
        }
    }

    int q;
    cin>>q;

    for(ll i = 0;i<q;i++){
        ll x,k;
        cin>>x>>k;
        x--;

        if(k <= n){
            cout<<v[k][x]<<endl;
        }
        else{
            cout<<v[n][x]<<endl;
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
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}