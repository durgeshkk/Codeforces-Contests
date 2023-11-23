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

    int f = 0,c=0,d=0;

    if(is_sorted(s.begin(),s.end())){
        cout<<"YES\n";
        return;
    }
    else{
        int y = 0;

        for(int i=s.length()-1;i>0;i--){
            if(s[i] == '0' && s[i-1] == '0'){
                y = i-1;
                f = 1;
                break;
            }
        }

        if(f == 0){
            cout<<"YES\n";
            return;
        }

        int f2 = 0;
        for(int i=y;i>0;i--){
            if(s[i] == '1' && s[i-1] == '1'){
                f2 = 1;
                break;
            }
        }

        if(f2 == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
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