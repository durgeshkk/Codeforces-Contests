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
/*
ll fun(ll y,ll x){
    queue<ll> q;
    ll cnt = 1,k = 1,tt=1;
    q.push(y);
    ll top = -1;

    while(!q.empty()){
        top = q.front();

        if(top == x){
            return k-1;
        }

        q.pop();
        q.push(top+k);
        q.push(top-1);
        cnt++;

        if(cnt%tt == 0){
            k++;
            tt *= 2;
            cnt = 0;
        }

    }
}
*/
void solve()
{
 
    ll x;
    cin>>x;
    /*
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }*/

    // ll ans = fun(0,x);
    ll i=1;
    for(i;i<x;i++){
        if((i*(i+1)) >= 2*x){//find just next greatest no.
            break;
        }
    }

    ll ans = (i*(i+1))/2;

    if(ans == (x+1)){
        cout<<i+1<<endl;
    }
    else{
        cout<<i<<endl;
    }
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