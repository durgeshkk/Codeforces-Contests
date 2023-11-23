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
 
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector<ll> v(n,0);

    ll tt = k;
    for(ll i = 0;i<n && tt>0;++i){
        if((k%2) == (s[i]-'0')){
            tt--;
            v[i]++;
        }
    }

    v[n-1] += tt;

    for(int i=0;i<n;++i)
    {
        if(((k-v[i])%2==1)){
           s[i] =('1'-(s[i]-'0'));
        }
    }
/*
    ll tt = min(cnt0,cnt1);
    if(k == 0){
        // cout<<s<<endl;
    }
    else if(k == 1){
        if(cnt1 >= 1){
            ll f = 0;
            for(ll i = 0;i<n;i++){
                if(s[i] == '1' && f == 0){
                    f = 1;
                    v[i]++;
                }
                else if(s[i] == '0'){
                    s[i] = '1';
                }
                else{
                    s[i] = '0';
                }
            }
            // cout<<s<<endl;
        }
        else{
            for(ll i = 0;i<n;++i){
                s[i] = '1';
            }
        }
    }
    else{
        if(k > tt){
            k -= tt;

            if(k%2)
            {
                for(ll i = 0;i<n;++i){
                    if(s[i] == '1'){
                        v[i]++;
                    }
                }

                v[s.size()-1] += k;
                for(ll i = 0;i<n-1;++i){
                    cout<<'1';
                }
                cout<<'0'<<endl;
            }
            else{

            }
        }


    }*/
    cout<<s<<endl;

    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
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