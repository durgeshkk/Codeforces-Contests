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
 
    ll n;
    cin>>n;

    char arr[n][n];

    for(ll i=0;i<n;i++){
        char prev = 'W';
        if(i%2){
            prev = 'B';
        }

        arr[i][0] = prev;
        for(ll j = 1;j<n;j++){
            if(prev == 'W'){
                arr[i][j] = 'B';
                prev = 'B';
            }
            else{
                arr[i][j] = 'W';
                prev = 'W';
            }
        }
    }

    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
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