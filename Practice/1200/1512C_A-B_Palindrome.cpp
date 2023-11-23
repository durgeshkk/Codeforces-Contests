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
 
    ll a,b;
    cin>>a>>b;

    string s;
    cin>>s;

    ll n = s.size();

    ll c0=0,c1=0,cq=0;
    for(ll i = 0;i<n;i++){
        if(s[i] == '0'){
            c0++;
        }
        else if(s[i] == '1'){
            c1++;
        }
        else{
            cq++;
        }
    }

    if(a%2!=0 && (b%2!=0)){
        cout<<-1<<endl;
        return;
    }

    if(c0 > a || c1>b ){
        // cout<<"HI 1 ";
        cout<<-1<<endl;
        return;
    }

    ll j = (n-1);
    for(ll i=0;i<n/2;i++,j--){
        if(s[i] == '0' && s[j] == '?'){
            s[j] = '0';
            c0++;
        }
        else if(s[i] == '?' && s[j] == '0'){
            s[i] = '0';
            c0++;
        }
        else if(s[i] == '1' && s[j] == '?'){
            s[j] = '1';
            c1++;
        }
        else if(s[i] == '?' && s[j] == '1'){
            s[i] = '1';
            c1++;
        }
        else if(s[i] == '0' && s[j] == '1'){
            cout<<-1<<endl;
            return;
        }
        else if(s[i] == '1' && s[j] == '0'){
            cout<<-1<<endl;
            return;
        }
    }

    if(c0 > a || c1>b ){
        // cout<<"HI 2 ";
        cout<<-1<<endl;
        return;
    }

    a -= c0,b-=c1;

    j = (n-1);
    for(ll i = 0;i<n/2;i++,j--){
        if(s[i] == '?' && s[j] == '?'){
            if(a >= 2){
                a-=2;
                s[i] = '0';
                s[j] = '0';
            }
            else if(b >= 2){
                b-=2;
                s[i] = '1';
                s[j] = '1';
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
    }
    // cout<<s<<endl;

    if(n%2){
        ll mid = (n/2);
        if(s[mid] == '?'){
            if(a == 1){
                s[mid] = '0';
            }
            else if(b == 1){
                s[mid] = '1';
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
    }

    if(isPalindrome(s)){
        cout<<s<<endl;
    }
    else{
        // cout<<"HI 4 ";
        cout<<-1<<endl;
    }
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