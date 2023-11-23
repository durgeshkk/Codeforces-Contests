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

    string s;
    cin>>s;

    vector<ll> w;

    ll fb=0,fr=0;
    ll b=0,r=0;
    ll prev=-1;
    for(ll i=0;i<n;i++){
        if(s[i] == 'B'){
            fb++;
            b++;
        }
        else if(s[i] == 'R'){
            fr++;
            r++;
        }
        else{
            prev = i;
            if(fb == 0 && fr == 0){
                continue;
            }

            if(fb == 0 || fr == 0){
                cout<<"NO\n";
                return;
            }
            fb = 0;
            fr = 0;
        }
    }

    // if((b == 0 && r == 0)|| ((b+r) == n)){
    //     cout<<"YES\n";
    //     return;
    // }

    // if(b == 0 || r == 0){
    //     cout<<"NO\n";
    //     return;
    // }

    if(prev == -1 && (b!=0 && r!=0)){
        cout<<"YES\n";
        return;
    }
    else if(prev == -1 && (b==0 || r==0)){
        cout<<"NO\n";
        return;
    }

    if(prev == (n-1)){
        cout<<"YES\n";
        return;
    }

    fb = 0,fr =0;
    for(ll i = prev;i<n;i++){
        if(s[i] == 'B'){
            fb++;
        }
        else if(s[i] == 'R'){
            fr++;
        }
    }

    if(fb == 0 || fr == 0){
        cout<<"NO\n";
        return;
    }

/*
    if((fb == 0 && fr == 0)|| ((fb+fr) == n)){
        cout<<"YES\n";
        return;
    }

    if(fb == 0 || fr == 0){
        cout<<"NO\n";
        return;
    }
    if(n > 2){
        if((s[1] == 'W') || 
        for(ll i = 0;i<n;i++){
        }
    }
    if(w.size() == 0){
        cout<<"YES\n";
        return;
    }
    for(ll i = 0;i<w.size()-1;i++){
        cout<<w[i]<<" ";
    }
    cout<<endl;

    if((w[0])%2 == 0){
        cout<<"NO\n";
        return;
    }

    for(ll i = 0;i<w.size()-1;i++){
        if((w[i+1]-w[i])%2 == 0){
            cout<<"NO\n";
            return;
        }
    }
*/

    cout<<"YES\n";
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