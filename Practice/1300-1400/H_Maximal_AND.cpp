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
    ll mod = 1e9+7;
    ll n;
    cin>>n;

    ll k;
    cin>>k;

    ll arr[31];
    for(ll i=0;i<31;i++){
        arr[i] = 0;
    }

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    sort(v.begin(),v.end());

    ll f = 0,idx = -1;
    for(ll i= 0;i<n;i++){
        bitset<31> s(v[i]);

        for(ll i = 30;i>=0;i--){

            if(s[i] == 1){
                if(f == 0){
                    idx = i;
                    f = 1;
                }
                arr[i]++;
            }
        }
    }

    // for(auto it = 0;it<31;it++){
    //     cout<<arr[it]<<" ";
    // }
    // cout<<endl;

    ll ans = 0;
    for(ll i = 30;i>= 0;--i){
        // cout<<i<<" "<<arr[i]<<" "<<k<<endl;
        ll req = n-arr[i];
        if((req) <= k){
            k -= (req);
            ans += (1<<i); 
            // for(ll j = 1;j<=i;j++){
            //     ans = ((ans*2)%mod);
            //     // ans = ((ans*2));
            // }
            // ans += (pow(2,i)%(1.0*mod));
        }
        // cout<<ans<<endl;
    }

    cout<<ans<<endl;

/*
    for(auto it = 0;it<31;it++){
        cout<<arr[it]<<" ";
    }
    cout<<endl;
*/
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