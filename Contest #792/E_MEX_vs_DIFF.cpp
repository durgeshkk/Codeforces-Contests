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
 
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
       cin>>v[i];
       mp[v[i]]++;
    }

    sort(v.begin(),v.end());

    ll diff = mp.size();
    ll mex = 0;  

    if(k >= (mp.size()-1)){
        cout<<0<<endl;
        return;
    }

    ll t = k;
    ll prevnum = -1;
    ll mex1 = 0;

    for(ll i = 0;i<n;i++){
        if(mp.find(i) == mp.end()){
            t--;
            if(t == (k-1)){
                mex1 = i;
            }
            if(t == -1 && (i!=0)){
                mex = i;
                break;
            }
            else if(t == -1 && (i ==0)){
                mex = i;
                break;
            }
        }
        else{
            prevnum = i;
            continue;
        }
    }

    ll ans = max(diff-mex,)
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