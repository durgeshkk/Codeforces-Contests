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
 
    ll n;
    cin>>n;
    string s;
    cin>>s;
/*
    char ch = s[0];
    char small = s[0];
    ll ind = -1;
    for(ll i=1;i<n;i++){
        if(small > s[i]){
            small = s[i];
            ind = i;
            // break;
        }
    }
    // cout<<ind<<endl;
    if(ind == -1){
        cout<<ch<<ch<<endl;
    }
    else{
        string s1 = s.substr(0,ind+1);
        string s2 = s.substr(0,ind+1);
        // cout<<s1<<" "<<s2<<endl;
        reverse(s2.begin(),s2.end());

        s1 += s2;
        cout<<s1<<" "<<s<<endl;
        if(s1 > s){
            small = s[0];
            for(ll i=1;i<n/2;i++){
                if(small > s[i]){
                    small = s[i];
                    ind = i;
                    // break;
                }
            }

            if(ind == -1){
                cout<<ch<<ch<<endl;
            }
            else{
                s1 = s.substr(0,ind+1);
                s2 = s.substr(0,ind+1);
                // cout<<s1<<" "<<s2<<endl;
                reverse(s2.begin(),s2.end());

                s1 += s2;
                cout<<s1<<endl;
            }
                
        }
        else{
            cout<<s1<<endl;
        }
    }*/

    string ans = "";
    ans+=s[0];

    if(s[0] == s[1] || s[1]>s[0]){
        cout<<ans;
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
        return;
    }

    else{
        for(ll i=1;i<n;i++){
            if(s[i] <= s[i-1]){
                ans += s[i];
            }
            else{
                break;
            }
        }
    }
    cout<<ans;
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
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