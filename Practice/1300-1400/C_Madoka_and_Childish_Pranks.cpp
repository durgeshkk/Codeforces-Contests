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

    vector<string> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    string st = v[0];
    if(st[0] == '1'){
        cout<< -1<<endl;
        return;
    }

    ll ans = 0;
    for(ll i=0;i<n;i++){
        string s = v[i];
        for(ll j = m-1;j>0;--j) {
            if(s[j] == '1'){
                ans++;
                // cout<<(i+1)<<" "<<(j)<<" "<<(i+1)<<" "<<(j+1)<<endl;
            }
        }
    }

    string f;
    for(auto it:v){
        f += it[0];
    }

    // cout<<f<<endl;

    for(ll j=n-1;j>0;--j){
        if(f[j] == '1'){
            ans++;
        }
    }

    cout<<ans<<endl;

    for(ll i=0;i<n;i++){
        string s = v[i];
        for(ll j = m-1;j>0;--j) {
            if(s[j] == '1'){
                // ans++;
                cout<<(i+1)<<" "<<(j)<<" "<<(i+1)<<" "<<(j+1)<<endl;
            }
        }
    }
    
    for(ll j=n-1;j>0;--j){
        if(f[j] == '1'){
            cout<<j<<" "<<1<<" "<<(j+1)<<" "<<1<<endl;
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
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}