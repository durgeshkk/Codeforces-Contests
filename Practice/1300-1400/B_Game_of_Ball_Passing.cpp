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

    ll cnt = 0;
    vector<ll> v(n);
    map<ll,ll> mp;
    ll sm = 0;

    for(ll i=0;i<n;i++){
       cin>>v[i];
       if(v[i] == 0){
           cnt++;
       }
       sm += v[i];
       mp[v[i]]++;
    }

    if(n == cnt){
        cout<<0<<endl;
        return;
    }
    else if(mp.size() == 1){
        cout<<1<<endl;
        return;
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
/*
    ll mn = v[n-1];
    ll j = n-1,f = 0;
    for(ll i=n-1;i>=0;--i){
        v[i] -= mn;
        if(v[i] != 0 && f == 0){
            f = 1;
            j = i;
        }
    }

    if(j == 0){

    }
    ll sm1 = 0;
    for(ll i = 0;i<n;--j){

    }*/
    
    ll mx = v[0];
    if(sm >= (2*mx)){
        cout<<1<<endl;
    }
    else{
        cout<<abs(sm-2*mx)<<endl;
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