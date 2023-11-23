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
    vector<int> v(n);

    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    sort(v.begin(),v.end());

    int mn = INT16_MAX;
    int ele1,ele2;
    int idx1,idx2;

    for(int i = 0;i<n-1;i++){
        if(mn > (v[i+1]-v[i])){
            mn = (v[i+1]-v[i]);
            ele1 = v[i];
            ele2 = v[i+1];
            idx1 = i;
            idx2=(i+1);
        }
    }

    cout<<ele1<<" ";

    for(int i = idx2+1;i<n;i++){
        // if(i == idx1 || i == idx2){
        //     continue;
        // }
        cout<<v[i]<<" ";
    }

    for(int i = 0;i<idx1;i++){
        cout<<v[i]<<" ";
    }
    cout<<ele2<<endl;
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