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

        long long max = v[0],min = v[0];
        int max_ind = 0,min_ind=0;

        for(int i=0;i<s;i++){
            if(v[i] > max){
                max = v[i];
                max_ind = i;
            }
            else if(v[i] < min){
                min = v[i];
                min_ind = i;
            }
        }
        // +1 since given array starts with 1
        cout<<min_ind+1<<" "<<max_ind+1<<endl;
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