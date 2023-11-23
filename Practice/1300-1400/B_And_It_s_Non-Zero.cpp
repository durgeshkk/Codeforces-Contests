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

ll ak[200001][32] = {0};
void dk(){
    for(ll i=1;i<=200000;i++){
        bitset<20> s(i);
        for(ll j = 0;j<32;++j){
            if(i >= 1){
                ak[i][j] = ak[i-1][j];
            }
            if(s[j] == 1){
                ak[i][j]+=1;
            }
        }
    }
}

void solve(){

    ll l,r;
    cin>>l>>r;

/*
    map<ll,ll> ak;
    for(ll i = l;i<=r;++i){
        bitset<18> s(i);

        for(ll j = 0;j<=18;++j){
            if(s[j] == 1){
                ak[j]++;
            }
        }
    }
*/
    ll n = (r-l+1);
    ll ans = LLONG_MAX;

    for(ll i = 0;i<32;++i){
        ans = min(ans,n-ak[r][i]+ak[l-1][i]);
    }

    cout<<ans<<endl;
    return;
/*
    n = r-l+1;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       v[i] = (i+l);
    }

    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        bitset<18> s(v[i]);

        for(ll j = 0;j<=18;++j){
            if(s[j] == 1){
                mp[j]++;
            }
        }
    }

    ll ans = INT16_MIN;
    for(auto it:mp){
        ans = max(ans,it.second);
    }

    cout<<(n-ans)<<endl;*/
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
    dk();

   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}