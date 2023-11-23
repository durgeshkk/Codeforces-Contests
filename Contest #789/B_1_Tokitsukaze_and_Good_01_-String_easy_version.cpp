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

    ll ans = 0;
    ll cz=0,co = 0;

    for(ll i =0;i<n-1;i++){
        if(s[i] == '0'){
            cz++;
            if(s[i+1] == '1'){
                if(cz%2){
                    s[i] = '1';
                    cz = 0;
                    co = 1;
                    ans++;
                }
                else{
                    cz = 0;
                    co = 0;
                }
            }
            else{

            }
        }
        else{//s[i] == 1
            co++;
            if(s[i+1] == '0'){
                if(co%2){
                    s[i] = '0';
                    cz = 1;
                    co = 0;
                    ans++;
                }
                else{
                    cz = 0;
                    co = 0;
                }
            }
            else{

            }
        }
    }
    cout<<ans<<endl;
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