// Refer Sol E

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
 
    ll n,k;
    cin>>n>>k;
    ll mx = 0;
    char ch1,ch2;
    ch1 = 'z',ch2 = 'z';

    string s;
    cin>>s;

    for(ll i=0;i<n;i++){
        if(mx >= s[i]-'a'){ // Free of Cost
            s[i] = 'a';
        }
        else if(k>0){
            ll diff = (s[i]-'a')-mx;

            if(k >= diff){
                mx = max(mx,(ll)s[i]-'a');
                k-=diff;
                s[i] = 'a';
            }
            else{
                ch2 = s[i];
                s[i] -= k;
                ch1 = s[i];
                k = 0;
            }
        }
    }

    for(ll i= 0;i<n;i++){
        if(s[i]>= ch1 && s[i] <= ch2){
            s[i] = ch1;
        }
    }

    cout<<s<<endl;
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