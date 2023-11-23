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
 
    ll n;
    cin>>n;

    ll x;
    cin>>x;

    vector<ll> v(n),st(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
       st[i] = v[i];
    }

    sort(st.begin(),st.end());

    if(is_sorted(v.begin(),v.end())){
        cout<<"YES\n";
        return;
    }

    if(x == n){
        cout<<"NO\n";
        return;
    }

    if(2*x <= (n)){
        // cout<<"YES\n";
    }
    else{
        for(ll i = (n-x);i<x;i++){
            if(st[i] != v[i]){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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