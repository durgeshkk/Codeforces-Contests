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

    vector<ll> dia,min;
    for(ll i=0;i<2*n;i++){
        ll x,y;
        cin>>x>>y;

        if(x == 0){
            min.push_back(abs(y));
        }
        else{
            dia.push_back(abs(x));
        }
    }

    sort(min.begin(),min.end());
    sort(dia.begin(),dia.end());

    double cnt = 0;
    for(ll i = 0;i<n;i++){
        double a1 = 1.0*min[i]*min[i];
        double a2 = 1.0*dia[i]*dia[i];
        double ans = 1.0*sqrt((1.0*a1+1.0*a2));
        cnt+=(ans);
    }
    cout<<setprecision(20)<<cnt<<endl;
    
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   setprecision(20);
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}
