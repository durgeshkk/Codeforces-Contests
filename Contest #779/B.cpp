#include<bits/stdc++.h>
#define ll  long long int
using namespace std;

int fact(int n){
    if(n==1){
        return 1;
    }
    return ((n%998244353)*(fact(n-1)%998244353)%998244353);
}

void solve(){

    ll n;
    cin>>n;

    ll ans=1;
    if(n%2 != 0){
        cout<<0<<endl;
    }
    else{
        ll num = (n/2);
        ll f_ans = 0;
        while((num) != 1){
            ans = (ans*(num));
            f_ans = (((ans%998244353)*(ans%998244353))%998244353);
            num--;
        }
        cout<<(f_ans)<<endl;
    }
    return;
}

int main()
{
    int t;
    cin>>t;

    while(t != 0){
        solve();
        t--;
    }

    return 0;
}