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
 
    ll n,q;
    cin>>n>>q;
    // cout<<n<<" "<<q<<endl;

    ll sm = 0;
    map<ll,ll> mp;
    vector<ll> v(n);

    for(ll i=0;i<n;i++){
       cin>>v[i];
       sm += v[i];
       mp[i+1] = v[i];
    }
/*
    for(ll i=0;i<n;i++){
       cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<sm<<endl;
*/
    ll z = -1;
    for(ll i= 0;i<q;i++){
        ll a=-1;
        cin>>a;

        // cout<<a<<endl;

        if(a == 1){
            ll b,c;
            cin>>b>>c;
            // cin>>c;

            // cout<<"HI"<<b<<" "<<c<<endl;
            if(mp.find(b) == mp.end()){
                if(z != -1){
                    sm -= z;
                }
                mp[b] = c;
                sm += c;
            }
            else{
                ll diff = (c - mp[b]);
                sm += diff;
                mp[b] = c;
            }
        }
        else{
            ll b;
            cin>>b;
            // cout<<"HI2\n";
            sm = (n*b);
            z = b;
            mp.erase(mp.begin(),mp.end());
        }
        cout<<sm<<endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}