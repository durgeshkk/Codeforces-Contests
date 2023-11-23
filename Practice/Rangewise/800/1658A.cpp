#include<bits/stdc++.h>
using namespace std;

void solve(){

    long long size;
    cin>>size;

    string s;
    cin>>s;

    int ind = 0;
    long long count=0;//extra 1's to be added
    while(ind < (size-1)){
        if(s[ind] == '0' && s[ind+1] == '0'){
            count += 2;
        }
        else if(s[ind] == '0' && s[ind+1] == '1' && s[ind+2] == '0'){
            count += 1;
        }
        ind++;
    }
    cout<<count<<endl;
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