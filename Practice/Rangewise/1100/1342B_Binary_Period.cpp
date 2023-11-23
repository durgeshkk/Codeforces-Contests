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
 /*
    string t;
    cin>>t;

    ll ones=0,zero=0;
    for(ll i = 0;i<t.length();i++){
        if(t[i] == '0'){
            zero++;
        }
        else{
            ones++;
        }
    }

    if(zero == t.size() || ones == t.size()){
        t += t[0];
        cout<<t<<endl;
        return;
    }

    if(t.size() == 2){
        cout<<t<<endl;
        return;
    }

    string s;
    if(t[0]== '0'){
        for(ll i = 0;i<t.size()-1;i++){
            if(t[i] == '0' && t[i+1] == '0'){
                s+='0';
                s+='1';
            }
            else if(t[i] == '1' && t[i+1] == '1'){
                s+='1';
                s+='0';
            }
            else{
                s+=t[i];
            }
        }

        if(s.back() == '1'){
            if(s.size() > t.size()){

            }
            else{
                s+='0';
                s+='1';
            }
        }
        else{
            s += '1';
        }
    }
    else{
        for(ll i = 0;i<t.size()-1;i++){
            if(t[i] == '0' && t[i+1] == '0'){
                s+='0';
                s+='1';
            }
            else if(t[i] == '1' && t[i+1] == '1'){
                s+='1';
                s+='0';
            }
            else{
                s+=t[i];
            }
        }

        if(s.back() == '0'){
            if(s.size() > t.size()){

            }
            else{
                s+='1';
                s+='0';
            }
        }
        else{
            s += '0';
        }
    }

    cout<<s<<endl;*/
    
    string s;
    cin>>s;

    bool ans = true;
    int n = s.size();

    for(int i=1;i<n;i++){
        if(s[i] != s[i-1]){
            ans = false;
            break;
        }
    }

    if(ans){//all char in s r same
        cout<<s<<endl;
    }
    else{
        string t = "";
        for(int i=0;i<n;i++){
            t += "10";
        }
        cout<<t<<endl;
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