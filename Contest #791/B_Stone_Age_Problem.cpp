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

    ll q;
    cin>>q;

    vector<ll> v(n);
    map<ll,ll> m;
    ll sm = 0;
    for(ll i=0;i<n;i++){
       cin>>v[i];
       sm += v[i];
    }

    // ll sm = accumulate(v.begin(),v.end(),0);

    ll prev = -1;
    
    for(ll i = 0;i<q;i++){
        ll a = -1,b = -1,c=-1;
        cin>>a;

        if(a == 1){
            cin>>b;
            cin>>c;
            /*
            ll ele = v[b-1];
            v[b-1] = c;
            sm -= ele;
            sm += c;*/

            auto it = m.find(b-1);

            if(it != m.end()){
                sm -= m[b-1];
            }
            else if(prev != -1){
                sm -= prev;
            }
            else{
                sm -= v[b-1];
            }
            sm += c;
            m[b-1] = c; 
            cout<<sm<<endl;
        }
        else{
            cin>>b;
            sm = (b*n);
            prev = b;
            // vector<ll> v2(n,b);
            // v.assign(v.size(),b);
            // fill(v.begin(),v.end(),b);
            // v = v2;
            /*
            for(ll i=0;i<n;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;*/
            m.clear();
            cout<<sm<<endl;
        }
        
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t = 1;
   while (t--)
   {
       solve();
   }
   return 0;
}