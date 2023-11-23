#include<bits/stdc++.h>
using namespace std;

void solve(){

    long long l,r,k;
    cin>>l>>r>>k;

    long long size = r-l+1;
    long long f=0;//if sequence staRTS with odd

    // Set flag = 1 if sequence starts with even
    if(l%2 == 0){
        f = 1;
    }

    long long odd_count=0;

    if(f == 0){
        odd_count = (size+1)/2;
    }
    else{
        odd_count = size/2;
    }

    if(k==0 && size == 1){
        if(l == 1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    else{
        if(k==0){
            cout<<"NO\n";
            // return;
        }
        else if(k < (odd_count)){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
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