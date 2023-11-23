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
 
    ll n,x,y;
    cin>>n>>x>>y;

    string s;
    cin>>s;

    
    reverse(s.begin(),s.end());

    ll cnt=0;
    for(int i = 0;i<x;i++){
        if(s[i] == '0'){
            if(i == y){
                cnt++;
                s[i] = '1';
            }
        }
        else{
            if(i == y){
                continue;
            }
            s[i] = '0';
            cnt++;
        }
        // cout<<s<<" "<<cnt<<endl;
    }

    // if(s[y] == '1'){

    // }
    // else{
    //     cnt++;
    //     s[y] = '1';
    // }
    reverse(s.begin(),s.end());
    // cout<<s<<endl;
    cout<<cnt<<endl;
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