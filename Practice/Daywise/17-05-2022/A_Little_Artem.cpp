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
 
    ll n,m;
    cin>>n>>m;
/*
    vector<string> v(n);

    if(n%2 == 0 && m%2 == 0){
        for(ll i = 0;i<n;i++){
            string s;

            char prev = 'W';
            if(n%2){
                prev = 'B';
            }
            s += prev;

            for(ll j = 1;j<m;j++){
                if(prev == 'B'){
                    s += 'W';
                    prev = 'W';
                }
                else{
                    s += 'B';
                    prev = 'B';
                }
            }
            v[i] = (s);
        }
    }
    else if(n%2 != 0 && m%2 == 0){

        for(ll i = 0;i<n;i++){
            string s;
            char prev = 'W';
            if(n%2==0){
                prev = 'B';
            }
            s += prev;

            for(ll j = 1;j<m;j++){
                if(prev == 'B'){
                    s += 'W';
                    prev = 'W';
                }
                else{
                    s += 'B';
                    prev = 'B';
                }
            }

            if(i == n-1){
                s[m-1] = 'B';
            }
            v[i] = (s);
            // v.push_back(s);
        }
    }
    else if(n%2 == 0 && m%2 != 0){
        for(ll i = 0;i<n;i++){
            string s;

            char prev = 'W';
            if(n%2==0){
                prev = 'B';
            }
            s += prev;

            for(ll j = 1;j<m;j++){
                if(prev == 'B'){
                    s += 'W';
                    prev = 'W';
                }
                else{
                    s += 'B';
                    prev = 'B';
                }
            }

            if(i == n-1){
                s[m-1] = 'B';
            }
            v[i] = (s);
            // v.push_back(s);
        }
    }

    else{//both odd
        for(ll i = 0;i<n;i++){
            string s;

            char prev = 'B';
            if(n%2==0){
                prev = 'W';
            }
            s += prev;

            for(ll j = 1;j<m;j++){
                if(prev == 'B'){
                    s += 'W';
                    prev = 'W';
                }
                else{
                    s += 'B';
                    prev = 'B';
                }
            }

            if(i == n-1){
                s[m-1] = 'B';
            }

            v[i] = (s);
            // v.push_back(s);
        }
    }

    for(ll i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }*/
    
    if (n == 2 || m == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    cout << 'W';
                }
                else
                {
                    cout << 'B';
                }
            }
            cout << endl;
        }
 
        return;
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0 || i == 1 && j == 0)
            {
                cout << 'W';
            }
            else
            {
                cout << 'B';
            }
        }
        cout << endl;
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