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
    
    if(n <= 1){
        cout<<1<<endl;
        cout<<n<<endl;
        return;
    }

    vector<string> v;
    ll f = 1;

    string st = to_string(n);

    for(ll i = 0;i<st.size();i++){
        string s;
        s+=st[i];
        if(st[i] == '0'){
            continue;
        }
        for(ll j = i+1;j<st.size();j++){
            s += '0';
        }
        v.push_back(s);
    }

    // while(n>0){
    //     ll rem = n%10;
    //     if(f == 1){
    //         cout<<rem<<endl;
    //         n /= 10;
    //         f = 0;
    //         continue;
    //     }
        // n /= 10;
    // }
    cout<<v.size()<<endl;
    for(ll i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // cout<<"HI\n";
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