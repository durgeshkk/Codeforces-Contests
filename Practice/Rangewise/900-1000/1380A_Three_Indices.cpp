#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }

    ll left = -1,right=-1;
    ll f=0;

    for(ll i=1;i<n-1;i++){
        for(ll j=0;j<i;j++){
            if(v[j]<v[i]){
                f=1;
                left = j;
            }
        }

        if(f == 1){
           for(ll j=i+1;j<n;j++){
                if(v[j]<v[i]){
                    f=2;
                    right = j;
                }
            } 
        }

        if(f == 2){
            cout<<"YES\n";
            cout<<left+1<<" "<<i+1<<" "<<right+1<<endl;
            return;
        }
    }
    cout<<"NO\n";
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
   return 0;
}