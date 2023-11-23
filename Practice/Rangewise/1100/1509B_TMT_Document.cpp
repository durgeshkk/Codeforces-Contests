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
 
void solve()
{
 
    ll n;
    cin>>n;

    string s;
    cin>>s;

    // if(s[s.size()-1] == 'M'){
    //     cout<<"NO\n";
    //     return;
    // }

    ll countM = 0;
    ll countT = 0;
    ll ans = 0;

    for(ll i=0;i<n;i++){
        if(s[i] == 'M'){
            countM++;
            ans--;
        }
        else{
            countT++;
            ans++;
        }

        if(ans < 0){
            cout<<"NO\n";
            return;
        }
    }

    ans = 0;
    for(ll i=n-1;i>=0;i--){
        if(s[i] == 'M'){
            ans--;
        }
        else{
            ans++;
        }

        if(ans < 0){
            cout<<"NO\n";
            return;
        }
    }

    if(countT == (countM*2)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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