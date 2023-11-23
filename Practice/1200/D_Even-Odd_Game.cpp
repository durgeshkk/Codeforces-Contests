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
 
    int n;
    cin>>n;
    vector<int> v(n),alice,bob;
    for(int i=0;i<n;i++){
       cin>>v[i];
    }

    sort(v.begin(),v.end(),greater <int> ());

    // ll ans1 = 0,ans2 = 0;
    for(int i = 0;i<n;i++){
        if((i%2) == 0){
            if(v[i]%2){

            }
            else{
                // ans1 += v[i];
                alice.push_back(v[i]);
            }
        }
        else{
            if(v[i]%2){
                // ans1 -= v[i];
                // ans2 += v[i];
                bob.push_back(v[i]);
            }
        }
    }

// /*
    ll ans1 = 0,ans2 = 0;
    for(ll i = 0;i<alice.size();i++){
        // cout<<alice[i]<<" ";
        ans1 += alice[i];
    }
    // cout<<endl;

    for(ll i = 0;i<bob.size();i++){
        ans2 += bob[i];
        // cout<<bob[i]<<" ";
    }
    // cout<<endl;*/
    /*
    int ans1 = accumulate(alice.begin(),alice.end(),0);
    int ans2 = accumulate(bob.begin(),bob.end(),0);
*/
    if(ans1>ans2){
        cout<<"Alice\n";
    }
    else if(ans1 == ans2){
        cout<<"Tie\n";
    }
    else{
        cout<<"Bob\n";
    }
    /*
    if(ans1 == 0){
        cout<<"Tie\n";
    }
    else if(ans1>0){
        cout<<"Alice\n";
    }
    else{
        cout<<"Bob\n";
    }
    */

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