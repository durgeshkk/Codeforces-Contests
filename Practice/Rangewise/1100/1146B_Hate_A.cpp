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
 
    string t;
    cin>>t; 

    ll coa=0;
    for(ll i=0;i<t.size();i++){
        if(t[i] == 'a'){

        }
        else{
            coa++;
        }
    }

    if(coa%2){
        cout<<":(\n";
        return;
    }

    ll req = (coa/2);

    reverse(t.begin(),t.end());

    string sub;
    for(ll i = 0;i<req;i++){
        sub += t[i];
    }

    reverse(t.begin(),t.end());
    reverse(sub.begin(),sub.end());
    
    for(ll i = 0;i<req;i++){
        if(sub[i] == 'a'){
            cout<<":(\n";
            return;
        }
    }

    string s;
    for(ll i =0;i<(t.size()-req);i++){
        if(t[i] == 'a'){

        }
        else{
            s+=t[i];
        }
    }

    if(s == sub){
        string ans;

        for(ll i=0;i<(t.size()-req);i++){
            ans += t[i];
        }
        cout<<ans<<endl;
    }
    else{
        cout<<":(\n";
    }

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    ll t;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
   solve();
   return 0;
}