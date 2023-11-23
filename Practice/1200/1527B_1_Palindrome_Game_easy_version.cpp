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

    string s;
    cin>>s;

    ll c1=0,c2=0;
    for(ll i =0;i<n;i++){
        if(s[i] == '1'){
            c1++;
        }
        else{
            c2++;
        }
    }

    if(n%2){
        ll mid = n/2;

        if(s[mid] == '0'){
            if(n == 1){
                cout<<"BOB\n";
                return;
            }
            else if(c1 == (n-1)){
                cout<<"BOB\n";
                return;
            }
            else if(c1 == (n)){
                cout<<"DRAW\n";
                return;
            }
            else{
                cout<<"ALICE\n";
            }
        }
        else{
            cout<<"BOB\n";
        }
    }
    else{
        // if(n == 2 && c2==n){
        //     cout<<"DRAW\n";
        // }
        if(c1 == n){
            cout<<"DRAW\n";
        }
        else{
            cout<<"BOB\n";
        }
    }
    
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