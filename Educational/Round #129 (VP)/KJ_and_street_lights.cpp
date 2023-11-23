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
 
    int n,p;
    cin>>n>>p;

    // if(n == 0){
    //     cout<<p+1<<endl;
    //     return;
    // }

    vector<int> v(p+2,0);

    for(int i = 0;i<n;++i){

        int a,b;
        cin>>a>>b;
        // a--,b--;

        // if(a < 0){
        //     a = 0;
        // }
        
        // if(b < 0){
        //     b = 0;
        // }

        int l = a-b;
        int r = a+b+1;

        if(l <= 0){
            l = 0;
        }

        if(r >= p+1){
            r = p+1;
        }

        v[l] += 1;
        v[r] -= 1;
    }

    for(int i = 1;i<=p;++i){
        v[i] += v[i-1];
    }

    int ans = 0,cnt = 0;
    for(int i = 0;i<=p;++i){
        if(v[i] != (1)){
            cnt++;
        }
        else{
            ans = max(cnt,ans);
            cnt = 0;
        }
    }
    cout<<max(ans,cnt);
/*
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }*/
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