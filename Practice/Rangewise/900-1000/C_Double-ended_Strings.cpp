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
 
    string s,t;
    cin>>s>>t;

    // /*
    //Approach 1:
    int lcs = 0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            int a=i,b=j;
            int len = 0;

            while(a<s.size() && b<t.size() && s[a++]==t[b++]){
                len++;
            }
            lcs = max(len,lcs);
        }
    }
    cout<<s.size()+t.size()-2*lcs<<endl;
    // */

// Approach 2:DP
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