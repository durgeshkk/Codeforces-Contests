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
 
    ll n,k,x;
    cin>>n>>k>>x;

    vector<ll> v(n),diff;
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    sort(v.begin(),v.end());

    for(ll i = 0;i<n-1;i++){
        if((v[i+1] - v[i]) > x){

            ll t = (v[i+1] - v[i]);
            diff.push_back(t);
        }
    }

    // for(ll i = 0;i<diff.size();i++){
    //     cout<<diff[i]<<" ";
    // }
    // cout<<endl;

    ll cnt = 0;
    sort(diff.begin(),diff.end());

    // for(ll i = 0;i<diff.size();i++){
    //     cout<<diff[i]<<" ";
    // }
    // cout<<endl;

    ll req = 0;
    for(ll i = 0;i<diff.size();i++){
        if(diff[i]%x == 0){
            ll ans = ((diff[i]/x)-1);

            if(ans <= k){
                k -= ans;
            }
            else{
                req += (ans-k);
                cnt++;
            }

        }
        else{
            ll ans = (diff[i]/x);

            if(ans <= k){
                k -= ans;
            }
            else{
                req += (ans-k);
                cnt++;
            }
        }
    }

    // cout<<req<<endl;
    cout<<cnt+1<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}