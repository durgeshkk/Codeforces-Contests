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
 
    ll n;
    cin>>n;
    
    vector<ll> pos;
    set<ll>zero;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
       cin>>v[i];

        if(v[i]>0)
        {
           pos.push_back(i);
        }

       if(v[i] == 0){
           zero.insert(i);
        //    zero.push_back(i);
       }
    }

    for(ll i=1;i<pos.size();++i)
    {
        if(pos[i]-pos[i-1] == 1)
        {
            cout<<"NO\n";
            return;
        }
        else if(pos[i]-pos[i-1] == 2)
        {
            ll t1 = pos[i];
            ll t2 = pos[i-1];

            ll fd = (t1+t2)/2;

            if(zero.find(fd) != zero.end())
            {
                cout<<"NO\n";
                return;
            }
        }
    }

    ll prev = *zero.begin();

    ll l = prev,r=-1,f = 0;
    for(ll i = prev;i<n-1;i++){
        if(zero.find(i+1) != zero.end() && (zero.find(i) != zero.end())){
            if(f == 0){
                l = i;
            }

            f = 1;
            continue;
        }
        else{
            r = i;
            f = 0;
        }

        if(l>0 && r<n-1){
            if(v[l-1] > 0 && v[r+1]>0){
                cout<<"NO\n";
                return;
            }
        }
    }
/*
    for(auto it:zero){
        if(it == 0){
            continue;
        }
        else if(it-1 == prev){
            prev = it;
            continue;
        }
    }
*/
    cout<<"YES\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}