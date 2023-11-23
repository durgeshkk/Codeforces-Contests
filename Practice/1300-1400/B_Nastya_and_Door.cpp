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
 
    ll n,k;
    cin>>n>>k;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    ll l = 0,r = (k-1);
    ll peak = 0,idx = 0;

    for(ll i = 1;i<k-1;++i){

        if((v[i]>v[i-1]) && (v[i]>v[i+1])){
            peak++;
        }
    }

    ll p = peak;
    for(ll i = 1;r<n-1;++i){

        if(v[r]>v[r-1]){
            if(v[r] > v[r+1]){
                p++;
            }
        }

        r++,l++;

        if(v[l]>v[l-1]){
            if(v[l] > v[l+1]){
                p--;
            }
        }

        if(p > peak){
            peak = p;
            idx = i;
        }
    }

    cout<<peak+1<<" "<<idx+1<<endl;
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