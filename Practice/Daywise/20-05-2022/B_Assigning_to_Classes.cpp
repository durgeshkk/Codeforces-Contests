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
    vector<ll> v(2*n);
    for(ll i=0;i<2*n;i++){
       cin>>v[i];
    }

    sort(v.begin(),v.end());

    if(n == 1){
        cout<<abs(v[1]-v[0])<<endl;
        return;
    }
/*
    if(n == 1){
        cout<<v[0]<<endl;
        return;
    }

    
    ll mn= INT16_MAX;
    for(ll i=0;i<2*n-1;i++){
        ll diff = abs(v[i+1]-v[i]);

        if(diff < mn){
            mn = diff;
        }
    }
    ll ans = mn;

    if(n%2){
        vector<ll> v1(n);
        vector<ll> v2(n);
        ll j = 0;
        for(ll i=0;i<2*n;i+=2,j++){
            v1[j] = (v[i]);
            v2[j] = (v[i+1]);
        }

        ll ans = abs(v1[n/2] - v2[n/2]);
        cout<<ans<<endl;
    }
    else{
        vector<ll> v1(n-1);
        vector<ll> v2(n+1);

        ll j = 0;
        for(ll i=0;i<n-1;i++,j++){
            v1[j] = (v[i]);
        }
        for(ll i=0;i<n-1;i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
        j = 0;
        for(ll i=(n-1);i<2*n;i++,j++){
            v2[j] = (v[i]);
        }
        /*
        for(ll i=0;i<n+1;i++){
            cout<<v2[i]<<" ";
        }
        cout<<endl;

        ll ans = abs(v1[v1.size()/2] - v2[v2.size()/2]);
        cout<<ans<<endl;
    }*/
    
    cout<<abs(v[n-1] - v[n])<<endl;
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