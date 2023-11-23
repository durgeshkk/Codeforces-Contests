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
 
    ll a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;

    if(a1 == b1 || a2 == b2){
        cout<<"No\n";
        return;
    }

    if(b1 > a1){
        swap(b1,a1);
    }
    
    if(b2 > a2){
        swap(b2,a2);
    }
   
//     ll t1 = max(a1,a2);
//     ll t2 = max(b1,b2);

//    ll t3 = min(a1,b1);
//    ll t4 = min(b2,a2);

    if(a1 == a2){
        if((b1+b2) == a1){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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