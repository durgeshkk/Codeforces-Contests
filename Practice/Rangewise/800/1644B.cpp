#include<bits/stdc++.h>
using namespace std;

void display(vector<long long> a,int n){
    for(int it = 0;it < n;it++){
        cout<<a[it]<<" ";
    }
    cout<<endl;
}


void solve(){
    
        long long s;
        cin>>s;

        int k;
        cin>>k;

        vector<long long> v;

        for(int i=0;i<s;i++){
            // long long ele;
            // cin>>ele;
            v.push_back(i+1);
        }

        int i=0;
        while(next_permutation(v.begin(),v.end())){
            if(v[i-2]+v[i-1] == v[i]){
                continue;
            }
            display(v,v.size());
            i++;
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