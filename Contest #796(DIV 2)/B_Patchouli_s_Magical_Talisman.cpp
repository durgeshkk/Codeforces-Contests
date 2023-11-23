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

    ll f = 0;
    ll even = 0;
    ll four = 0;
    ll odd = 0;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];

       if((v[i]%2) != 0){
           f = 1;
           odd++;
       }
       else{
            even++;
            if((v[i]%4) == 0){
                four++;
            }
       }
    }

    if(odd == n){
        cout<< 0 <<endl;
        return;
    }

    if(f == 1){
        cout<< even <<endl;
        fflush(stdout);
        return;
    }
/*
    if(four == 0){
        cout<< n <<endl;
        fflush(stdout);
    }
    else if(four == n){
        sort(v.begin(),v.end());

        ll ele = v[0];
        ll ans = 3;
        ll fl = 0;
        // ll mn = INT16_MAX;
        for(ll i = 0;i<n;++i){

            if((v[i]%8) != 0){
                ans = 2;
                fl = 1;
                break;
            }
            // while(1){
            //     ele = (ele/2);
            //     ans++;

            //     if(ele%2){
            //         break;
            //     }
            // }   

            // if(mn < ans){
            //     ans = mn;
            // }
        }

        if(fl == 0){

            ans = 0;
            while(1){
                ele = (ele/2);
                ans++;

                if(ele%2){
                    break;
                }
            }   
        }
        ans += (n-1);
        cout<<ans<<endl;
        fflush(stdout);
    }
    else{
        ll tt = (n-four-1);
        cout<< (four+1+tt) <<endl;
        fflush(stdout);
    }
*/

    ll sm =0,mx = LLONG_MAX,ans = 0;
    for(ll i=0;i<n;i++){
        sm=v[i];
        ans=0;
        while(sm%2==0){
            ans++;
            sm= sm/2 + sm%2;
        }
        mx = min(ans,mx);
    }
            
    cout<<(mx+n-1)<<endl;
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