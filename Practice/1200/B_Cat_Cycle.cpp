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

    ll ans = 0;
    if(n%2){
        /*
        ll gap = ceil(1.0*n/2);

        ll tt = n*(gap-1);

        if(n == 3){
            tt = 3;
        }
        vector<ll> v;

        ll z = 0;
        ll a = 0;
        for(ll i=1;z<=tt;i++){
            i %= n;
            if(a == (gap-1)){
                a = 0;
                continue;
            }
            
            v.push_back(i);
            a++;
            z++;
        }
        // reverse(v.begin(),v.end());

        for(ll i = 0;i<tt;i++){
            if(v[i] == 0){
                v[i] = n;
            }
        }
*/
        k--;
        ll val = (n/2);
        ll ans = ((k + (n%2) * k/val)%n)+1;
        cout<<ans<<endl;
    }
    else{
        if(k%n == 0){
            k = n;
        }
        else{
            k = (k%n);
        }
        ans = k;
        cout<<ans<<endl;
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