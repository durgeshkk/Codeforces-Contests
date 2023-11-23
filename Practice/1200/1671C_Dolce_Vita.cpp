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
 
    ll n,x;
    cin>>n>>x;

    ll sm = 0;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
        sm += v[i];
    }

    sort(v.begin(),v.end());
/* TLE (mine approach):
    ll last = -1,sm = 0;
    for(ll i = 0;i<n;i++){
        sm += v[i];
        if(x < sm){
            sm -= v[i];
            break;
        }
        last = i;
    }

    if(last == -1){
        cout<<0<<endl;
        return;
    }

    last++;
    ll cnt = 0;
    ll ans = last;
    while(last > 0){
        sm += last;
        cnt++;

        if(sm > x){
            // cout<<sm<<" "<<"Last : "<<last<<endl;
            sm = sm - cnt - v[last-1];
            last--;
            ans += last;
            // cout<<cnt<<" "<<sm<<endl;
            continue;
        }
        // cout<<"Last : "<<last<<" ";
        ans += last;
        // cout<<"Ans : "<<ans<<endl;
    }
    cout<<ans<<endl;*/
    
    // Optimised :
    ll day = 0,ans=0;
    for(ll i=n-1;i>=0;i--){
        if(sm > x){
            sm -= (v[i]+day);
            continue;
        }
        //rem & add are logic of A.P.
        ll rem = x-sm;
        ll add = rem/(i+1);//d = i+1
        ans += ((add+1)*(i+1));
        day += (add+1);//days = n+1
        sm += ((add+1)*(i+1));
        sm -= (v[i]+day);
    }
    cout<<ans<<endl;
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