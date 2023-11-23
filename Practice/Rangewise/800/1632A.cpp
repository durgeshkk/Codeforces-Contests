#include<bits/stdc++.h>
using namespace std;

void solve(){

    long long size;
    cin>>size;

    string num;
    cin>>num;

    long long freq_1=0;
    long long freq_0=0;
    for(long long i=0;i<num.size();i++){
        if(num[i] == '0'){
            freq_0++;
        }
        else if(num[i]=='1'){
            freq_1++;
        }
        if((freq_0>1) || (freq_1>1)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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