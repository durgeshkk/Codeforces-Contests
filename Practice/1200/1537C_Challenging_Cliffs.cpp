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
 
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
       cin>>v[i];
    }

    sort(v.begin(),v.end());

    // if(n == 2){
    //     cout<<v[0]<<" "<<v[1]<<endl;
    //     return;
    // }

    int mn = 2e9;
    int idx1=(-1);

    for(int i = 1;i<n;i++){
        if(mn > abs(v[i]-v[i-1])){

            mn = abs(v[i]-v[i-1]);
            idx1 = i;
        }
    }

/*
    for(int i = idx1;i<n;i++){
        cout<<v[i]<<" ";
    }

    for(int i = 0;i<idx1;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;*/

    vector<int>small,big;
    for(int i=0;i<n;i++){
        if((i==idx1) || (i==idx1-1)){
            continue;
        } 
        if(v[i]>v[idx1-1]) big.push_back(v[i]);
    }

    for(int i=0;i<n;i++){
        if((i==idx1) || (i==idx1-1)){
            continue;
        }
        if(v[i]<=v[idx1]) small.push_back(v[i]);
    }

    cout<<v[idx1-1]<<" ";
    for(auto i : big) cout<<i<<" ";
    for(auto i : small) cout<<i<<" ";
    cout<<v[idx1]<<" "<<"\n";
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