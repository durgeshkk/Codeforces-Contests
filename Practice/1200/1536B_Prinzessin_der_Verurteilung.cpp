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

    map<char,ll> mp;
    for(ll i = 0;i<26;i++){
        mp['a'+i]=0;
    }

    for(ll i = 0;i<n;i++){
        mp[s[i]]++;
    }
    
    for(auto it:mp){
        if(it.second == 0){
            cout<<it.first<<endl;
            return;
        }
    }

    mp.erase(mp.begin(),mp.end());

    map<string,ll> mp2;
    for(ll i = 0;i<26;i++){
        string s1;
        char c1 = 'a'+i;
        for(ll j = 0;j<26;j++){
            s1 += c1;
            char c2 = 'a'+j;
            s1 += c2;
            mp2[s1] = 0;
            s1 = "";
        }
    }

    for(ll i = 0;i<n-1;i++){
        string st;
        st += s[i];
        st += s[i+1];
        mp2[st]++;
    }

    for(auto it:mp2){
        if(it.second == 0){
            cout<<it.first<<endl;
            return;
        }
    }

    mp2.erase(mp2.begin(),mp2.end());
/*
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int f = 0;
            string st = "";
            st += mp[i];
            st += mp[j];
            for (int k = 0; k < n; k++)
            {
                if (s.substr(k, 2) == st)
                {
                    f = 1;
                }
            }
            if (f == 0)
            {
                cout << st << endl;
                return;
            }
        }
    }
*/

    for(ll i = 0;i<26;i++){
        string s1;
        char c1 = 'a'+i;
        for(ll j = 0;j<26;j++){
            char c2 = 'a'+j;
            for(ll k = 0;k<26;k++){
                char c3 = 'a'+k;
                s1 += c1;
                s1 += c2;
                s1 += c3;
                mp2[s1] = 0;
                s1 = "";
            }
        }
    }

    for(ll i = 0;i<n-2;i++){
        string st;
        st += s[i];
        st += s[i+1];
        st += s[i+2];
        mp2[st]++;
    }

    // for(auto it:mp2){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    for(auto it:mp2){
        if(it.second == 0){
            cout<<it.first<<endl;
            return;
        }
    }
    // cout<<-1<<endl;
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