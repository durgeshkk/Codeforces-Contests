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
    ll a[n][m];

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    ll f = 0;
    ll idx1 = -1,idx2=-1;

    for(ll i=0;i<n;i++){
        multiset <ll> mp;
        for(ll j=0;j<m;j++){
            mp.insert(a[i][j]);
        }
        
        ll j = 0;
        for(auto it:mp){
            if(it != a[i][j] && (idx1 == -1)){
                idx1 = j;
            }
            
            else if(it != a[i][j] && (idx2 == -1)){
                idx2 = j;
                f = 1;
            }
            
            else if(it != a[i][j] && (idx2 != -1)){
                cout<<-1<<endl;
                return;
            }

            j++;
        }

        if(f == 1){
            break;
        }
    }

    if(idx1 == -1 && idx2 == -1){
        cout<<1<<" "<<1<<endl;
        return;
    }

    for(ll i=0;i<n;i++){
        swap(a[i][idx1],a[i][idx2]);
    }

    for(ll i=0;i<n;i++){
        ll prev = a[i][0];
        for(ll j=0;j<m;j++){
            if(a[i][j] < prev){
                cout<<-1<<endl;
                return;
            }
            prev = a[i][j];
        }
    }

    if(idx1 == -1 && idx2 == -1){
        cout<<1<<" "<<1<<endl;
        return;
    }

    cout<<idx1+1<<" "<<idx2+1<<endl;

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