#include<bits/stdc++.h>
using namespace std;

void solve(){

    long long l1,l2,l3;
    cin>>l1>>l2>>l3;

    if(l1 == l2){
        if(l3%2 == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else if(l2 == l3){
        if(l1%2 == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else if(l1 == l3){
        if(l2%2 == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else{
        if((l3 == l1+l2) || (l1 == l3+l2) || (l2 == l1+l3)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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