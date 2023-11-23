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
 
    ll n,m;
    cin>>n;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    cin>>m;
    vector<ll> v2(m);
    for(ll i=0;i<m;i++){
       cin>>v2[i];
    }

    ll mx1 = *max_element(v.begin(),v.end());
    ll mx2 = *max_element(v2.begin(),v2.end());
    // cout<<mx1<<" "<<mx2<<endl;

    if(mx1 > mx2){
        cout<<"Alice\n";
        cout<<"Alice\n";
    }
    else if(mx1 == mx2){
        cout<<"Alice\n";
        cout<<"Bob\n";
    }
    else{
        cout<<"Bob\n";
        cout<<"Bob\n";
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