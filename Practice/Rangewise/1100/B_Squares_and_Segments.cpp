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
    
    if(n <= 3){
        cout<<n+1<<endl;
        return;
    }

    ll t = sqrt(n);
    ll a = 2*t;

    ll sq = (t*t);
    ll diff = n-sq;

    if(diff == 0){
        cout<<a<<endl;
        return;
    }
    if(diff <= t){
        cout<<a+1<<endl;
    }
    else{
        cout<<a+1+1<<endl;
    }
    /*
    // ll c = n/sq;
    ll b = ceil(1.0*n/sq);
    ll sub = (n-sq-1);
    ll half = (n/2);
    ll b = ceil(1.0*sub/half);
    cout<<a+b<<endl;
*/

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