#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m,a;
    cin>>n>>m>>a;

    if(a == 1){
        if(n == 1 && m==1){
            cout<<1<<endl;
        }
        else{
            cout<<n*m<<endl;
        }
        return;
    }

    ll num_square=0;
    if(n%a == 0 && m%a==0){
        num_square += (n*m)/(a*a);
    }
    else if(n%a == 0){
        ll extra_m = m%a;
        num_square += (n*(m-extra_m))/(a*a);
        num_square += (n/a);
    }
    else if(m%a==0){
        ll extra_n = n%a;
        num_square += (m*(n-extra_n))/(a*a);
        num_square += (m/a);
    }
    else{
        ll extra_m = m%a;
        ll extra_n = n%a;
        num_square += ((m-extra_m)*(n-extra_n))/(a*a);
        num_square += (m/a);
        num_square += (n/a);
        num_square++;
    }
    cout<<num_square<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
//    ll t;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
   solve();
   return 0;
}