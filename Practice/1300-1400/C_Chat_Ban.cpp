#include<bits/stdc++.h>
// #include<iomanip>
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

    if(n*n <= x){
        cout<< (2*n-1) <<endl;
    }
    else if( (n*(n+1)/2) > x){

        ll tt = ceil(1.0*((sqrt((1+(8*x))))-1)/2);
        cout<< tt <<endl;
    }
    else{
        x -= (n*(n+1)/2);

        ll ans = floor(1.0*((sqrt(1.0*(1+(8*((n*(n-1)/2) - x)))))-1)/2);
        cout<< (2*n-1-ans) << endl;
    }

/*
    for(ll i=0;i<(2*n-1);i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
*/
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