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

ll bs(ll n,vector<ll> &v,ll sm){
    ll low = 1,high = v[n-1];

    ll ans = INT16_MAX;
    // ll req = n*n;
    while(low<=high){

        ll mid = (low+high)/2;

        ll s = 0;
        for(ll i = 0;i<n;++i){
            s += (v[i]/mid);
        }

        if(s<=sm){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

void solve()
{
 
    ll n;
    cin>>n;

    ll req;
    cin>>req;

    vector<ll> v(n);
    for(ll i = 0;i<n;++i){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    ll ans = bs(n,v,req);
    cout<< ans << endl;
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