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
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    if(n == 1){
        cout<<0<<endl;
        return;
    }
    
    if(v[n-1] < (n-1)){
        // cout<<"HI\n";
        cout<<-1<<"\n";
        return;
    }

    else{
        // if(is_sorted(v.begin(),v.end())){
        //     // cout<<"HI\n";
        //     cout<<0<<endl;
        //     return;
        // }
        // else{
            ll count = 0;
            set<ll> s;
            reverse(v.begin(),v.end());
            s.insert(v[0]);

            for(ll i=1;i<n;i++){
                while(v[i]>=(*s.begin())){
                    count++;
                    v[i] /= 2;
                }

                if((i<n-1) && (v[i]==0)){
                    cout<<-1<<"\n";
                    return;
                }
                s.insert(v[i]);
            }
            cout<<count<<endl;
        // }
    }
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