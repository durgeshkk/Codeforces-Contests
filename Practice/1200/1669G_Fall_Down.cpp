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

    char v[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
/*
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/

    stack<char> s;

    char ans[n][m];
    for(ll j = 0;j<m;j++){
        char a[n];
        ll k=0;
        for(ll i = n-1;i>=0;i--){
            if(v[i][j] == '.'){
                // cout<<"HI\n";
                if(s.top() == '*'){
                    while(!s.empty()){
                        char ele = s.top();
                        s.pop();
                        a[k]=ele;
                        k++;
                    }
                }

                s.push('.');
            }
            else if(v[i][j] == '*'){
                s.push('*');
            }
            else{
                /*
                for(ll l=k;l<;l++,k++){
                    ans[k] = '.';
                }*/
                
                while(!s.empty()){
                    char ele = s.top();
                    s.pop();
                    a[k]=ele;
                    k++;
                }
                a[k] = v[i][j];
                k++;
            }
        }

        while(!s.empty()){
            char ele = s.top();
            s.pop();
            a[k]=ele;
            k++;
        }

        reverse(a,a+n);
        for(ll i = 0;i<n;i++){
            v[i][j] = a[i];
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

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