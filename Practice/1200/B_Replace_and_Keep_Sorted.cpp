#include<bits/stdc++.h>
#include<iomanip>
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
 
    ll n,q,k;
    cin>>n>>q>>k;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    for(ll i = 0;i<q;i++){
        ll l,r;
        cin>>l>>r;
/*
        l--,r--;
        ll st = v[l];
        ll e = v[r];

        map<ll,ll> mp;
        for(ll i = st;i<=e;i++){
            mp[i] = 0;
        }

        for(ll i =l;i<=r;i++){
            mp[v[i]]++;
        }

        ll a1 = v[l]-1;
        ll a2 = (k-v[r]);
        ll ans = 0;

        for(auto it:mp){
            if(it.second == 0){
                ans += 2;
            }
        }*/

        // for(ll i = l;i<=r;i++){
        //     if(mp.find(v[i]) == mp.end()){
        //     }
        // }

        // cout<<(ans+a1+a2)<<endl;
/*
        if(l == r){
            cout<<(k-1)<<endl;
            continue;
        }

        l--,r--;
        
        vector<ll> z(r-l+1);
        ll j = 0;
        for(ll i = l;i<=r;i++,j++){
            z[j] = v[i];
        }      
        // /*
        // for(ll i = 0;i<z.size();i++){
        //     cout<<z[i]<<" ";
        // }
        // cout<<endl;
        if(l+1 == r){
            ll a1 = (k-v[l]-1);
            ll a2 = (v[r]-2);
            // if(a1 == 0){
            //     a1 = 1;
            // }
            // cout<<a1<<" "<<a2<<endl;
            cout<<(a1+a2)<<endl;
            continue;
        }

        ll a1 = (z[1]-2); 
        for(ll i = 1;i<z.size()-1;i++){
            ll t = (z[i+1]-z[i-1]-2);
            // if(t == 0){
                // t = 1;
            // }

            a1 += t;
        }

        ll tz = k-z[z.size()-2]-1;
        a1 += tz;
        cout<<a1<<endl;*/

        cout<<( k + v[r-1] - v[l-1] - 2*(r - l) - 1) << "\n";
    }

    
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll t=1;
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}