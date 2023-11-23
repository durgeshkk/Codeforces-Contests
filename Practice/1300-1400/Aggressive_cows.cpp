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

bool canplace(vector<ll> v,ll n,ll cows,ll mid){

    ll cnt = 1;
    ll coor = v[0];

    for(ll i = 1;i<n;++i){
        if((v[i]-coor) >= mid){
            cnt++;
            coor = v[i];
        }
    }

    if(cnt >= cows){
        return true;
    }

    return false;
}

ll bs(vector<ll> &v,ll n,ll cows){
    ll low = 1,high = (v[n-1]-v[0]);
    ll ans = 0;

    while(low <= high){
        ll mid = (low+high)/2;

        if(canplace(v,n,cows,mid)){
            // ans = low;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return high;
}

void solve()
{
 
    ll n,cows;
    cin>>n>>cows;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    sort(v.begin(),v.end());

    ll ans = bs(v,n,cows);
    cout << ans << endl;
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