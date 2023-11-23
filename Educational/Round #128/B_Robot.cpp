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
 
    ll n,m;
    cin>>n>>m;

    vector<string> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    if(min(n,m) == 1){
        cout<<"YES\n";
        return;
    }

    vector<ll> ans;
    ll f = 1;
    ll l = -1,r=-1;
    ll rpres = -1;

    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            if(v[i][j] == 'R'){
                l = i;
                r = j;
                rpres++;
                // f = 1;
                // ans.push_back(j);
                break;
            }
        }
        if(l != -1){
            break;
        }
    }

    if(rpres == -1){
        cout<<"NO\n";
        return;
    }

    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<r;j++){
            if(v[i][j] == 'R'){
                f = 0;
            }
        }
    }

    if(f){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";

/*
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;     
    }

    for(ll i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
        cout<<endl;     
*/
    /*if(is_sorted(ans.begin(),ans.end())){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }*/
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