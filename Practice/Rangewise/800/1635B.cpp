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

        for(int i=0;i<size;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
        }

        int no_changed=0;
        for(int i=1;i<size-1;i++){
            /*
            if((i+1)==(size-1)){ //can't change 
                v[i-1] = v[i];
                no_changed++;
            }*/
            
            if(1){//Handle Corner case of i,i+1,i+2

            }
            else if((v[i]>v[i+1])&&(v[i]>v[i-1])){//change ele at i+1 & replace by v[i]
                v[i+1] = v[i];
                no_changed++;
            }
        }                

        cout<<no_changed<<endl;

        for(auto it: v){
            cout<<it<<" ";
        }

        cout<<endl;
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