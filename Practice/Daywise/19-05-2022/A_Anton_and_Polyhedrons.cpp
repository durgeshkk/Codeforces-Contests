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

    vector<string> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    ll sm = 0;
    for(ll i = 0;i<n;i++){
        if(v[i] == "Icosahedron"){
            sm += 20;
        }
        else if(v[i] == "Cube"){
            sm += 6;
        }
        else if(v[i] == "Tetrahedron"){
            sm += 4;
        }
        else if(v[i] == "Dodecahedron"){
            sm += 12;
        }
        else{
            sm += 8;
        }
    }
    cout<<sm<<endl;
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