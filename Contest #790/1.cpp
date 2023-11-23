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
 
void solve()
{
 
    string s;
    cin>>s;

    vector<char> v;
    vector<char> v2;

    ll s1 = 0;
    for(ll i=0;i<3;i++){
        s1 += s[i]-'0';
        v.push_back(s[i]);
    }
     
     ll s2=0;
    for(ll i=3;i<6;i++){
        s2 += s[i]-'0';
        v2.push_back(s[i]);
    }

    if(s1 == s2){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return;
    /*
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());

    for(ll i=0;i<3;i++){
        if(v[i] != v2[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";*/
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