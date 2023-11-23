#include<bits/stdc++.h>
#include<iomanip>
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
/*
    ll cnt = 0;
    if(n%2){
        n += 1;
        cnt++;
    }
    
    bitset<15> s(n);
    // cout<<s<<endl;

    ll f = 0,idx = -1,idx1 = -1;

    for(ll i = 0;i<15;i++){

        if(s[i] == 1){
            idx1 = i+1;
            break;
        }
        // else if(s[0] == 1 && f == 1){
        //     f = 1;
        //     idx = i+1;
        // }
        // else{
            // f = 0;
        //     break;
        // }
    }

    // cout<<idx1<<endl;
    ll ans1 = cnt + (16-idx1);
    // cout<<"Ans 1 : "<<ans1<<endl;
    // cout<<idx1<<endl;

    for(ll i = 14;i>=(idx1-1);--i){
        if(s[i] == 0){
            // cout<<"HI ";
            cout<<ans1<<" ";
            return;
        }
    }

    ll ans2 = 1;
    for(ll i = 1;i<(idx1-1);++i) {
        ans2 += (2*i);
        // cout<<"Ans 2 : "<<ans2<<endl;
    }
    ans2++;

    cout<<min(ans1,ans2)<<" ";

    // for (ll i = 0; i < n; i++)
    // {
    //     ll t = v[i];
    */

    if (n == 0){
        cout<<0<<" ";
        return;
    }

    ll ans = 15;
    for (ll j = 0; j <= 15; j++)
    {
        ll x = n+j;
        ll tt = 0;

        while (x%2 == 0 && x != 0)//extract 2 count
        {
            x = x / 2;
            tt++;
        }
        ans = min(ans, j + 15 - tt);
    }
    cout<<ans<< " ";
    return;
}

 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}