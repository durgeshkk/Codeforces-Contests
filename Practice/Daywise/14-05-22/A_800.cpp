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
 
// /*    
    string s;
    cin>>s;
    ll j = 1;

    if(s[0] == '9'){
        for(ll i =1;i<s.size();i++){
            if((s[i]-'0') < 5){
                continue;
            }
            else{
                ll num = (s[i]-'0');
                num = 9-num;
                s[i] = (char(num)+'0');
            }
        }
    }
    else{
        for(ll i =0;i<s.size();i++){
            if(s[i]-'0' < 5){
                continue;
            }
            else{
                ll num = s[i]-'0';
                num = 9-num;
                s[i] = (char(num)+'0');
            }
        }
    }

    cout<<s<<endl;
    // */
/*
    ll rem = n%10;
    ll num = 0;

    while(n > 0){
        rem = n%10;
        if(rem > 5){
            rem = (9-rem);
        }
        else{
            rem = rem;
        }

        ll t = n;
        while(t > 0){
            num += (num*10 + rem);
        }

        n/=10;

        if(n <= 9){
            if(n == 9){
                num += (num*10 + 9);
            }
            else if(n == 0){
                break;
            }
            else{
                if(n > 5){
                    rem = (9-rem);
                }
                else{
                    rem = rem;
                }
            }
            num += (num*10 + rem);
            break;
        }
    }

    n = num;
    ll remainder = 0,reversed_number=0;
    while(n != 0) {
        remainder = n % 10;
        reversed_number = reversed_number * 10 + remainder;
        n /= 10;
    }
    cout<<reversed_number<<endl;*/
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