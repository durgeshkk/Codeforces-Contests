#include<bits/stdc++.h>
#include<iomanip>
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

    vector<ll> v;
/*
    ll arr[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;++j){
            cin>>arr[i][j];
        }
    }
*/
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;++j){
            ll t1 = max(n-i-1,i);
            ll t2 = max(m-j-1,j);
            v.push_back(t1+t2);
        }
    }

    sort(v.begin(),v.end());

    // cout<<v.size()<<endl;
    for(ll i = 0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return;

}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}