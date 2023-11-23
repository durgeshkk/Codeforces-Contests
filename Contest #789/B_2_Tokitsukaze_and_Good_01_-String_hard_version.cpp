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

    ll last = -1,seg=0,cnt=0;

    for(ll i=0;i<n;i+=2){
        if(s[i] == s[i+1]){
            if(s[i]-'0' != last){
                last = s[i]-'0';
                seg++;
            }
        }
        else{
            cnt++;
        }
    }
    // ll ans = max(seg,1);
    cout<<cnt<<" "<<max(seg,1LL)<<endl;    
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