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

    set<ll> s;
    for(ll i=1;i<=n;i++){
       s.insert(i);
    }

    vector<ll> v(n);
    vector<ll> ans;

    for(ll i=0;i<n;i++){
       cin>>v[i];
       if(s.find(v[i]) != s.end()){
           s.erase(s.find(v[i]));
       }
       else{
           ans.push_back(v[i]);
       }
    }

    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());

    bool f = false;

    for(auto it:ans){
        auto it2 = s.end();
        ll val = *(--it2);

        ll mx = ((it-1)/2);//max produce pssbl

        if(mx < val){
            f = true;
            break;
        }
        s.erase(it2);
    }

        if(f){
            cout<< -1 <<endl;
            return;
        }

        /*
        if(mx < (i+1)){
            cout<< -1 <<endl;
            // cout<< "HI" <<endl;
            return;
        }
        else{
            // ans++;
        }*/
    cout<< ans.size() << endl;
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