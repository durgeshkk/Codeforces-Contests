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
 
    ll n,x,y;
    cin>>n>>x>>y;

    vector<ll> v(n);
    ll sm = 0;

    for(ll i=0;i<n;i++){
       cin>>v[i];
       sm += v[i];
    }

    if(sm%2){
        if((x%2 != 0 && y%2 == 0) || (x%2 == 0 && y%2 != 0)){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
        }
    }
    else{
        if((x%2 == 0 && y%2 == 0) || (x%2 != 0 && y%2 != 0)){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
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