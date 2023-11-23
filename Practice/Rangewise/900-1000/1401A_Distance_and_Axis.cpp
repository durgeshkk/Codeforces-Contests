#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,k;
    cin>>n>>k;

    if(k > n){
        cout<<k-n<<endl;
        return;
    }
    /*
    double b1 = 1.0*(0+n)/2;
    ll b2 = (0+n)/2;
    // cout<<b1<<" "<<b2<<endl;
    if(b1 == b2 && n!=0){
        cout<<0<<endl;
    }
    else{
        cout<<abs(k-n)<<endl;
    }*/

/*1st appr : correct  
If A is even then k can only be even no. in between  
So if both k & A even they we don't need to shift any of them
if k is odd then shift a by 1
And similar case for A is odd.
If A is odd then k can only be odd no. in between  
Thus answers can only be 0 or 1 in this case.

k <= x : 
    1. x is even
        1.1 k is even
        1.2 k is odd
    2. x is odd
        2.1 k is odd
        2.2 k is even

    ll total=0;
    ll x=0;//only made for max since max consider 0 as int
    total = total + max(x,k-n);
    n += total;
    if(k&1){//k is odd
        if(n%2==0){//n even then only add 1
            total++;
        }
    }
    else if(k%2 == 0){//k even
        if(n&1){//n odd then only add 1
            total++;
        }
    }
    cout<<total<<endl;*/

    // 2nd approach
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