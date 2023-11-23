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

    ll n = s.size();
    ll ind = -1,sus=0;

    if(n == 1){
        cout<<1<<endl;
        return;
    }


    for(ll i=0;i<n;i++){
        if(s[i] == '0'){
            ind = i;
            break;
        }
        if(s[i] == '?'){
            sus++;
        }
    }


    if(ind == -1 && (sus==n)){
        cout<<n<<endl;
        return;
    }

    if(ind  == -1){
        if(s[n-1] == '1'){
            cout<<1<<endl;
        }
        else{
            ll ans = 0;
            for(ll i=n-1;i>=0;i--){
                if(s[i] == '?'){
                    ans++;
                }
                else if(s[i] == '1'){
                    cout<<ans+1<<endl;
                    return;
                }
            }
        }
        return;
    }

    ll found = -1;
    sus = 0;
    ll f = 0;
    for(ll i=ind-1;i>=0;i--){
        if(s[i] == '1'){
            found = i;
            f = 1;
            break;
        }
        if(s[i] == '?'){
            sus++;
        }
    }

    // if(found == -1){
    //     cout<<ind+1<<endl;
    //     return;
    // }

    if(f == 1){
        cout<<ind-found+1<<endl;
    }
    else{
        cout<<ind+1<<endl;
    }

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