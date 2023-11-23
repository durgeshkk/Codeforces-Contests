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

void tree(ll l,ll r,vector<ll> &v,vector<ll> &dep,ll currdepth){

    if(l > r){
        return;
    }

    if(l == r){//for 1 ele left
        dep[l] = currdepth;
        return;
    }

    ll mx = l;//will become root
    for(ll i = l+1;i<(r+1);i++){
        if(v[mx] < v[i]){
            mx = i;
        }
    }

    dep[mx] = currdepth;
    tree(l,mx-1,v,dep,currdepth+1);
    tree(mx+1,r,v,dep,currdepth+1);
}

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
       cin>>a[i];
    }

    vector<ll> dep(n);
    tree(0,n-1,a,dep,0);

    for(ll i = 0;i<dep.size();i++){
        cout<<dep[i]<<" ";
    }
    cout<<endl;
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