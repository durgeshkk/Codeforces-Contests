#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    vector<long long> ans;
    
    while(t != 0){

        int size;
        cin>>size;

        vector<long long> v;
/*
        for(int i =0;i<size;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
        }
*/
        int sum = pow(2,size);
        ans.push_back(sum-1);

        t--;
    }

    for(auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}