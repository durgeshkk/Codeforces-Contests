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
 
void solve()
{
 
    ll n,m;
    cin>>n>>m;

    vector<string> v;
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }

    ll mn = INT16_MAX;
    vector<ll> sum;

    for(ll i=0;i<n;i++){
        string s = v[i];
        for(ll j =i+1;j<n;j++){
            ll sm = 0;
            for(ll k=0;k<m;k++){
                sm += abs(v[i][k] - v[j][k]);
            }
            // cout<<sm<<endl;
            if(sm < mn){
                mn = sm;
            }
        }
        // cout<<endl;
    }

    cout<<mn<<endl;
    // cout<<endl;
/*
        for(ll j = i+1;j<n;j++){
            ll s2 = 0;
            for(ll j =0;j<m;j++){
                s2 += (v[i][j] -'a');
            }
            cout<<s2<<endl;
            if(abs(s1-s2) < mn){
                mn = abs(s1-s2);
            }
        }
    }

    cout<<mn<<endl;*/
    
    // sort(sum.begin(),sum.end());
    // ll ans = INT16_MAX;

    // for(ll i = 0;i<sum.size()-1;i++){
    //     ll st = (sum[i+1]-sum[i]);

    //     if(st < ans){
    //         ans = st;
    //     }
    // }

    // cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}