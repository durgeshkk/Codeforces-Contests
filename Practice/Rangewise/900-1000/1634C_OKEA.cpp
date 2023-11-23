#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n,k;
    cin>>n>>k;

    if(k==1){
        cout<<"YES\n";
        for(ll i=1;i<=n;i++){
            cout<<i<<endl;
        }
        // cout<<endl;
        return;
    }

    // For n being odd like 3x2 matrix :
    // 1 3 
    // 5 2 : will disturb the integer mean 
    // 4 6
    if(n%2 != 0){
        cout<<"NO\n";
        return;
    }

    // But k being odd will return valid permutation : 2x3
    // 1 3 5 : 9/3 ,{ 4/2 , 8/2}
    // 2 4 6 : 12/3 ,{ 6/2 , 10/2}
    cout<<"YES\n";

    // Now only possible when all evens & odds come together..
    // since we need mean to be an integer
    for(ll i=1;i<= (n*k);i+=2){
        ll c=0;

        while(c<k){
            cout<<i<<" ";
            c++,i+=2;
        }

        i-=2;
        cout<<endl;
    }

    for(ll i=2;i<= (n*k);i+=2){
        ll c=0;

        while(c<k){
            cout<<i<<" ";
            c++,i+=2;
        }

        i-=2;
        cout<<endl;
    }


    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}