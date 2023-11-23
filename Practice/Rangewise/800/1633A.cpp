#include<bits/stdc++.h>
using namespace std;

void solve(){

    long long num;
    cin>>num;

    long long test = num%7;
    if(test == 0){
        cout<<num<<endl;
        return;
    }

    num = num-(num%10);
    for(long long i=0;i<10;i++){
        if(num%7==0){
            cout<<num<<endl;
            return;
        }
        num++;
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