#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    ll a,b,c;

/*
// TLE:
    ll f=0;

    for(ll i=2;i<n;i++){
        if(n%i == 0){
            for(ll j=(i*2);j<n;j+=i){
                if(j%i==0 && (n-j-i)%i==0){
                // if(__gcd(j,n-j-i) == i){
                    f=1;
                    a=j;
                    c=i;
                    b=n-i-j;
                    break;
                }
            }
        }
        if(f==1){
            break;
        }
    }

    if(f == 1){
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    else{
        c = 1;
        a = 3;
        b = n-a-c;
        if(__gcd(a,b) != 3){
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else{
            a = 5;
            b = n-a-c;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }*/

    if(n%2 == 0){
        cout<<n-3<<" "<<2<<" "<<1<<endl;
    }
    else{
        // 2 coprimes ka HCF is odd
        // isme GCD = 1 & agaar a=2 kiya toh as n is odd b will be even & gcd(a,b)=c will
        // not be satisfied
        ll t=(n-1)/2;

        if(t%2==0){
            cout<<t+1<<" "<<t-1<<" "<<1<<endl;
        }
        else{
            cout<<t+2<<" "<<t-2<<" "<<1<<endl;
        }
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