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
 
    ll n,d;
    cin>>n>>d;
    
    if(n >= d){
        cout<<"YES\n";
        return;
    }

    // ll x = 1;
    ll mn = d;

    if(n%2){
        ll m1 = (n/2);
        ll t1 = ceil(1.0*d/(m1+1)) + m1;
        ll m2 = (n/2)+1;
        ll t2 = ceil(1.0*d/(m2+1)) + m2;
        mn = min(t1,t2);
    }
    else{
        ll mid = (n/2);
        ll t = ceil(1.0*d/(mid+1)) + mid;
        mn = t;
    }
    /*
    for(ll i = 0;i<d;i++){
        ll t = ceil(1.0*d/(i+1)) + i;

        if(t < mn){
            mn = t;
        }
        // cout<<t<<" "<<mn<<" ";
    }*/
    // cout<<mn<<endl;
    if(mn <= n){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}