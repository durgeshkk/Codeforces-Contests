#include<bits/stdc++.h>
using namespace std;

void solve(){
        long long s;
        cin>>s;

        vector<long long> v;

        for(int i=0;i<s;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
        }

        // long long first = 0,last = v.size()-1;

// /*
        long long i=0,prev=0,coins=0;

        while(i < v.size() && v[i] != 0){//front traverse
            prev = i;
            i++;
        }

        long long j = v.size()-1,next = j;//reverse traverse
        while(j != 0 && v[j] != 0){
            next=j;
            j--;
        }

        coins = next-prev;

        if(coins<0){
            cout<<0<<endl;
        }
        else{
            cout<<coins<<endl;
        }
        return;
}


int main()
{
    int t;
    cin>>t;

    while(t--){

        solve();
        // cout<<endl;
    }
    return 0;
}