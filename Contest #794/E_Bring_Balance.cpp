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

    ll f = 0;
    ll sm = 0;
    ll t = 0;

    vector<ll> st,e;

    for(ll i = 0;i<n;i++){
        if(s[i] == '(' && (f == 0)){
            sm++;
        }
        else if(s[i] == ')' && (f == 0)){
            sm--;

            if((sm < 0) && (f == 0)){
                t = 1;
                f = 1;//unbalanced
                st.push_back(i+1);
            }
        }
        else{
            if(s[i] == '('){
                t--;

                if(t == 0){
                    f = 0;
                    e.push_back(i+1);
                }
            }
            else{
                t++;
            }
        }
    }

    cout<<st.size()<<endl;

    if(st.size() == 0){
        return;
    }
    else{
        for(ll i=0;i<st.size();i++){
            cout<<st[i]<<" "<<e[i]<<endl;
        }
        cout<<endl;
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