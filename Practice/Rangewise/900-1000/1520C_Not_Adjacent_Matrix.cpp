#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    ll m=0,c=1;
    ll ans[n][n];

    if(n == 1){
        cout<<1<<endl;
        return;
    }
    else if(n == 2){
        cout<<-1<<endl;
        return;
    }
    else{
        
        for(ll i=0;i<n;i++,c+=1){
            ans[i][i] = c;
        }

        for(ll i=1;i<n;i++){
            for(ll j=0;j<i;j++,c+=2){
                ans[j][i] = c;
                ans[i][j] = c+1;
            }
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
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
//    solve();
   return 0;
}