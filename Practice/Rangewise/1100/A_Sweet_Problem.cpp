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
 
/*
    // ll r,g,b;
    // cin>>r>>g>>b;

    
    ll mx = 1;
    if(r > g && r>b){
        mx = r;
    }
    else if(g > r && g>b){
        mx = g;
    }
    else{
        mx = b;
    }

    if((r == g || r == b) && (mx == r) ){
        if(r == g){
            cout<<(r+(b/2))<<endl;
        }
        else{
            cout<<(r+(g/2))<<endl;
        }
        return;
    }
    else if((r == g || g == b) && (mx == g)){
        if(r == g){
            cout<<(g+(b/2))<<endl;
        }
        else{
            cout<<(g+(r/2))<<endl;
        }
        return;
    }
    else if((b == g || r == b) && (mx == b)){
        if(b == g){
            cout<<(b+(r/2))<<endl;
        }
        else{
            cout<<(b+(g/2))<<endl;
        }
        return;
    }

    if(mx == r){
        if(g+b >= r){
            cout<<r<<endl;
        }
        else{
            cout<<(g+b)<<endl;
        }
        return;
    }
    else if(mx == g){
        if(r+b >= g){
            cout<<g<<endl;
        }
        else{
            cout<<(r+b)<<endl;
        }
        return;
    }
    else{
        if(g+r >= b){
            cout<<b<<endl;
        }
        else{
            cout<<(g+r)<<endl;
        }
        return;
    }*/
    vector<ll> v(3);
    for(ll i=0;i<3;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    ll diff = (v[2]-v[1]);

    if(diff == 0 || (((v[1]-v[0]) == 0) && diff == 0)){
        ll t1 = (v[0]/2);
        ll ans = (v[1]-t1) + (2*t1);
        cout<<ans<<endl;
        // return;
    }
    else if(v[0] > diff){
        v[0] -= diff;
        v[2] -= diff;
        ll t1 = (v[0]/2);
        ll ans = ((v[1]-t1) + (2*t1) + diff);
        cout<<ans<<endl;
    }
    else{
        ll t1 = v[0];
        ll ans = t1+v[1];
        cout<<ans<<endl;
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