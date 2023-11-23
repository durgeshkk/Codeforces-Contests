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
   
   string s[n];
   for(ll i =0;i<n;i++){
       cin>>s[i];
   }

   char c = s[0][1];
   int x= 1;

   if(s[1][0] == s[0][1]){
       if(s[n-1][n-2] == s[n-2][n-1] && s[n-1][n-2] != s[0][1]){
           cout<<0<<endl;
       }
       else if(s[n-1][n-2] == s[n-2][n-1] && s[n-1][n-2] == s[0][1]){
           cout<<2<<endl;
           cout<<n<<" "<<n-1<<endl;
           cout<<n-1<<" "<<n<<endl;
       }
       else if(s[n-1][n-2] != s[n-2][n-1]){
           if(s[n-1][n-2] == s[0][1]){
               cout<<1<<endl;
               cout<<n<<" "<<n-1<<endl;
           }
           else{
               cout<<1<<endl;
               cout<<n-1<<" "<<n<<endl;
           }
       }
   }
   else
        {
            if (s[n - 1][n - 2] == s[n - 2][n - 1])
            {
                if (s[n - 1][n - 2] == s[0][1])
                {
                    cout << 1 << "\n";
                    cout << 1 << " " << 2 << "\n";
                }
 
                else if (s[n - 1][n - 2] == s[1][0])
                {
                    cout << 1 << "\n";
                    cout << 2 << " " << 1 << "\n";
                }
            }
 
            else
            {
                if (s[n - 1][n - 2] == s[0][1])
                {
                    cout << 2 << "\n";
                    cout << 1 << " " << 2 << "\n";
                    cout << n-1 << " " << n << "\n";
                }
                else if (s[n - 1][n - 2] == s[1][0])
                {
                    cout << 2 << "\n";
                    cout << 2 << " " << 1 << "\n";
                    cout << n-1 << " " << n << "\n";
                }
                
            }
           
            
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