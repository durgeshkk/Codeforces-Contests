#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string S)
{
    string P = S;

    // Reverse the string P
    reverse(P.begin(), P.end());
 
    // If S is equal to P
    if (S == P) {
        return 1;
    }
    else {
        return 0;
    }
}

void solve(){
        long long size;
        cin>>size;

        long long k;
        cin>>k;

        string s;
        cin>>s;

        string p = s;
        reverse(p.begin(),p.end()); 

        long long ans=0;

        if((isPalindrome(s)) || k==0){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
/*
        for(int i=0;i<size;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
        }
*/
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