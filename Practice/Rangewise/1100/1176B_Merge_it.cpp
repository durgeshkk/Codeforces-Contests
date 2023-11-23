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
    for(ll i=0;i<n;i++){
       cin>>v[i];
       v[i] = (v[i]%3);
    }

    ll cnt1=0,cnt2=0,cnt3=0;
    for(ll i=0;i<n;i++){
        if(v[i] == 1){
            cnt1++;
        }
        else if(v[i] == 2){
            cnt2++;
        }
        else{
            cnt3++;
        }
    }

    ll ans = min(cnt1,cnt2);
    if(cnt1 == cnt2){
        cout<<ans+cnt3<<endl;
    }
    else if(cnt1 > cnt2){
        cnt1 -= cnt2;
        ll t1 = (cnt1/3);
        cout<<t1+ans+cnt3<<endl;
    }
    else{
        cnt2 -= cnt1;
        ll t1 = (cnt2/3);
        cout<<t1+ans+cnt3<<endl;
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