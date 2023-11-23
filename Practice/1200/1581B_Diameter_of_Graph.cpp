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
 
    ll n,m,k;
    cin>>n>>m>>k;

    // vector<ll> v(n);
    // for(ll i=0;i<n;i++){
    //    cin>>v[i];
    // }

    ll emn = (n-1);
    ll emx = n*(n-1LL)/2;

    if((emn > m) || (emx < m)){
        cout<<"NO\n";
        return;
    }
    else if(n == 1){
        if(k > 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else if(m < emx){
        if(k > 3){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else{
            if(k > 2){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
    }
    // cout<<"YES\n";
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