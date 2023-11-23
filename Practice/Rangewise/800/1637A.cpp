#include<bits/stdc++.h>
using namespace std;

void display(vector<long long> a,int n){
    for(int it = 0;it < n;it++){
        cout<<a[it]<<" ";
    }
    cout<<endl;
}


void solve(){
    
        long long size;
        cin>>size;

        // int k;
        // cin>>k;

        vector<long long> v;
        vector<long long> s;//sorted

        for(int i=0;i<size;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
            s.push_back(ele);
        }
        sort(s.begin(),s.end());

// If array is already sorted then only ans will be No else always ans will be yes
        int i=0;
        while(i<size){
            if(v[i] == s[i]){
                i++;
            }
            else{
                break;
            }
        }
        
        if(i == size){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
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