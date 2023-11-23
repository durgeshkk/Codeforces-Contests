#include<bits/stdc++.h>
using namespace std;

void solve(){

    // long long size;
    // cin>>size;

    string s;
    cin>>s;

    if(s.size() % 2 != 0){
        cout<<"NO\n";
    }
    else{
        long long mid = s.size()/2;
        long long j = s.size()/2;

        long long i=0;
        while(i < mid){
            if(s[i] != s[j]){
                cout<<"NO\n";
                return;
            }
            i++;
            j++;
        }
        cout<<"YES\n";
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