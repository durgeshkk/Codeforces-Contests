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
 
    ll a,b,ab,ba;
    cin>>a>>b>>ab>>ba;

    string s;
    cin>>s;

    ll n = s.size();

    ll f = 0;

    for(ll i = 0;i<n;i++){
        if(i+1 == n){
            f = 1;
        }
        if(s[i] == 'A' && s[i+1] == 'B' && f == 0){
            if(ab > 0){
                ab--;
                i++;
            }
            else{
                a--,b--;
                if(a<0 || b<0){
                    cout<<"NO\n";
                    return;
                }
                i++;
            }
        }
        else if(s[i] == 'B' && s[i+1] == 'A' && f == 0){
            if(ba > 0){
                ba--;
                i++;
            }
            else{
                a--,b--;
                if(a<0 || b<0){
                    cout<<"NO\n";
                    return;
                }
                i++;
            }
        }
        else if(s[i] == 'A'){
            if(a > 0){
                a--;
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
        else if(s[i] == 'B'){
            if(b > 0){
                b--;
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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