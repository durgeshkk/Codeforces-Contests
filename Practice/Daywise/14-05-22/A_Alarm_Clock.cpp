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
 
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    ll ans= b;
    ll cnt=0;

   if(b >= a){
       cout<<b<<endl;
       return;
   }
    else{
        if(c<=d){
            cout<<-1<<endl;
            return;
        }

        ll t = (c-d);

        ll rem = (a-b);
        ll sleep_pssbl = (c-d);
        cnt = ceil(1.0*rem/sleep_pssbl);
        // cout<<t<<endl;
        /*
        while(ans < (a)){
            ans += (t);
            cnt++;
        }*/
        // cout<<cnt<<" "<<ans<<endl;
        ll tmp = b + (cnt*c);
        cout<<tmp<<endl;
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