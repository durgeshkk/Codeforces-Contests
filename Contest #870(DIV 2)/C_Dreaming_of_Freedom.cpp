#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,m;
void printDivisors(){ 
    // Note that this loop runs till square root 
    for (ll i=1; i*i<=(n); i+=2) 
    { 
        if(i == 1){continue;}
        if (n%i == 0){ 
            // If divisors are equal, print only one 
            if(m >= i){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES\n";
            }
            return;
        } 
    } 
    cout<<"YES\n";
} 
  
void solve()
{
    
    cin>>n>>m;
    if(m == 1){
        cout<<"YES\n";return;
    }
    else if(n == 1){
        cout<<"YES\n";return;
    }
    
    if(m >= n){
        cout<<"NO"<<endl;return;
    }

    if(n & 1){
        printDivisors();
    }else{
        cout<<"NO"<<endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}