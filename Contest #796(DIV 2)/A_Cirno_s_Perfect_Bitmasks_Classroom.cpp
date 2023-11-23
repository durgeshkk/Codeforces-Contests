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
    
    bitset<31> s(n);

    ll y = n;
    bitset<31> sy(n);

    ll idx = -1;  
    ll f = 0;  
    for(ll i = 0;i<= 30;++i){
        if(s[i] == 1 && f==0){
            idx = i;
            f = 1;
            continue;
        }

        if(s[i] == 1 && f == 1){
            f++;
        }
    }

    // cout<<idx<<endl;
    if(idx == 0){
        // cout<<f<<endl;
        if(f >= 2){

        }
        else if(f == 1){
            sy[1] = 1;
            idx++;
        }
        else{
            sy[1] = 0;
        }
        /*
        if(s[1] == 1){
            sy[1] = 0;
        }
        else{
            sy[1] = 1;
        }*/

        for(ll i= idx+1;i<=31;++i){
            sy[i] = 0;
        }
    }
    else{
        sy[idx] = 1;

        if(f >= 2){
            for(ll i=0;i<=31;++i){
                if(i == idx){
                    continue;
                }
                sy[i] = 0;
            }

        }
        else{
            sy[0] = 1;

            for(ll i=1;i<=31;++i){
                if(i == idx){
                    continue;
                }
                sy[i] = 0;
            }
        }
    }
    // cout<<sy<<endl;
    // if(s[idx] == 1){
    //     sy[idx] = 1;
    //     if(s[1] == 0){
    //         sy[1] = 1;
    //     }
    //     else{
    //         sy[1] = 0;
    //     }
    // }
    // else{
    //     sy[0] = 0;
    //     if(s[1] == 0){
    //         sy[1] = 1;
    //     }
    //     else{
    //         sy[1] = 0;
    //     }
    // }

    // string sst = to_string(sy);
    ll ans = sy.to_ulong();
    cout<<ans<<endl;
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