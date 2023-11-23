#include<bits/stdc++.h>
using namespace std;

void solve(){
        long long s;
        cin>>s;

        int k;
        cin>>k;

        vector<long long> v;

        for(int i=0;i<s;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
        }

        for(int i=0;i<s;i++){
            v[i] = v[i]%k;
        }

        int sum = accumulate(v.begin(),v.end(),0);
        if(k == 1){
            cout<<"Yes\n";
        }
        else if(sum % k == 0){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
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