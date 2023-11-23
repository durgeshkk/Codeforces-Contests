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

    ll m,M;
    cin>>M>>m;

    if(((m+M) > (n-2)) || (abs(m-M) >= 2)){
        cout<<-1<<endl;
        return;
    }

/*
Samne se swap karne pe local min > mx & 
picche se swap karne pe vice versa..
*/
/*
    ll j = 1;
    vector<ll> ans;
    for(ll i = m;i<n;i++,j++){
        ans.push_back(v[i]);
        if(j <= m){
            ans.push_back(j);
        }
    }

    for(ll it: ans){
        cout<<it<<" ";
    }
    cout<<endl;*/

    if(m == 0 && M == 0){
        for(ll i = 0;i<n;i++){
            cout<<(i+1)<<" ";
        }
        cout<<endl;
    }
    else if(M == 1 && m == 0){
        for(ll i = 1;i<=(n-2);i++){
            cout<<(i)<<" ";
        }
        cout<<n<<" "<<n-1<<" ";
        cout<<endl;
    }
    else if(M == 0 && m == 1){
        cout<<2<<" "<<1<<" ";
        for(ll i = 3;i<=(n);i++){
            cout<<(i)<<" ";
        }
        cout<<endl;
    }
    else{
        ll x;
        if(M > m){//swap from end
            x = m+M+1;

            for(ll i=1;i<=(n-x);i++){
                cout<<i<<" ";
            }
            
            for(ll i=(n-x+1);i<=n;i+=2){
                cout<<i+1<<" "<<i<<" ";
            }
            cout<<endl;
        }
        else if(m>M){//swap from front
            x = m+M+1;

            for(ll i=1;i<=(x);i+=2){
                cout<<i+1<<" "<<i<<" ";
            }
            
            for(ll i=(x+1);i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{//both equal so traverse any & just swap last 2 no.
            x = m+M;
            for(ll i=1;i<=(x);i+=2){
                cout<<i+1<<" "<<i<<" ";
            }

            for(ll i=(x+1);i<=n-2;i++){
                cout<<i<<" ";
            }
            cout<<n<<" "<<n-1<<endl;
        }

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