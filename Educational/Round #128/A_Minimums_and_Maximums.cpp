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
 
    ll l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
/*
    if(l2<=r1 && l2>=l1){
        cout<<l2<<endl;
        return;
    }
    if(r2<=r1 && r2>=l1){
        cout<<r2<<endl;
        return;
    }

    if(l1 >= l2 && r1 <= r2){
        cout<<max(l1,l2)<<endl;
        return;
    }*/

    if(r1 >= l2 && l2 >= l1){
        cout<<l2<<endl;
    }
    else if(r1 >= l2 && l2 < l1 && l1<=r2){
        cout<<l1<<endl;
    }
    else{
        cout<<l1+l2<<endl;
    }

    // else{
    //     cout<<l1+l2<<endl;
    // }

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