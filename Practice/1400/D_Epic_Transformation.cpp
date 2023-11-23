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
    vector<ll> v(n);
    map<ll,ll> mp;
    ll mxf = 0;

    for(ll i=0;i<n;i++){
       cin>>v[i];
       mp[v[i]]++;

       if(mp[v[i]] > mxf){
           mxf = mp[v[i]];
       }
    }

    if(n%2){
        if(mxf <= (n/2)){
            cout<<1<<endl;
            // return;
        }
        else{
            ll ele_rem = n - mxf;
            mxf -= ele_rem;
            cout<<mxf<<endl;
        }
    }
    else{
        if(mxf <= (n/2)){
            cout<<0<<endl;
            // return;
        }
        else{
            ll ele_rem = n - mxf;
            mxf -= ele_rem;
            cout<<mxf<<endl;
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