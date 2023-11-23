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
 
    ll n;
    cin>>n;

    string s;
    cin>>s;

    char t = s[0];
    ll ans = 0;

    if(t == '0'){
        ll prev = -1;
        for(ll i = 1;i<n;i++){
            if(s[i] == '1'){

                if(prev == (i-1)){
                    ans++;
                }
                prev = i;
            }
        }
    }
    else{
        ll prev = -1;
        for(ll i = 1;i<n;i++){
            if(s[i] == '0'){

                if(prev == (i-1)){
                    ans++;
                }
                prev = i;
            }
        }
    }

    cout<<ans<<endl;
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