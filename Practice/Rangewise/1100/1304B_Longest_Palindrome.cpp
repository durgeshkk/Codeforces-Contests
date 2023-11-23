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

    ll m;cin>>m;

    vector<string> v;
    set<string> st;

    ll f = 0;
    ll cnt=0;

    string s1,mid,s2;

    for(ll i=0;i<n;i++){
        string s;
        cin>>s;

        if(isPalindrome(s)){
            f++;
            if(f > 1){

            }
            else{
                mid += s;
            }
        }

        reverse(s.begin(),s.end());
        if(st.find(s) == st.end()){
            reverse(s.begin(),s.end());
            st.insert(s);
        }
        else{
            cnt += (2*m);
            s1 += s;
        }
    }

    s2 = s1;
    reverse(s2.begin(),s2.end());

    if(f >= 1){
        ll t = m;
        cout<<cnt+t<<endl;
        s1 += mid;
        s1 += s2;
    }
    else{
        cout<<cnt<<endl;
        s1 += s2;
    }
    cout<<s1<<endl;
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