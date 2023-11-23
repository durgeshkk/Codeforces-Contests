#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    vector<ll> v;
    vector<ll> rev;
    for (int i = 0; i < n; i++)
    {
        ll ele;
        cin>>ele;
        v.push_back(ele);
        rev.push_back(ele);
    }

    ll ans[n];
/*TLE:
    for (int i = 0; i < n; i++)
    {
        if(v[i] == 0 || v[i] == 1){
            ans[i] =v[i];
        }
        else{
            ll num = v[i];
            if((i+1)<=v[i]){
                for(ll j=0;j<=i;j++){
                    ans[j] = 1;
                }
            }
            else{
                ll count = 0;
                for(ll j=i;count!=num;j--){
                    ans[j] = 1;
                    count++;
                }
            }
            
        }
    }

    for(ll i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    */

   reverse(rev.begin(),rev.end());

    ll num = rev[0];
    for(int i=0;i<n;i++){
        if(rev[i]>=num){
            num = rev[i];
        }
        if(num >= 1){
            rev[i]=1;
        }
        num--;
    }

    reverse(rev.begin(),rev.end());
    for(ll i=0;i<n;i++){
        cout<<rev[i]<<" ";
    }
    cout<<endl;
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