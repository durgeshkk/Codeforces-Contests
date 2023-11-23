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
 
    ll c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;

    if(c1==0 && c3 == 0 && c4 == 0){
        cout<<1<<endl;
        return;
    }

    if(c3){
        if(c1 == c4 && c1>0){
            cout<<1<<endl;
            return;
        }
    }
    else{
        if(c1 == c4){
            cout<<1<<endl;
            return;
        }
    }
    cout<<0<<endl;
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