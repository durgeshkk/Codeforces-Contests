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

        for(int i =0;i<size;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
        }

        sort(v.begin(),v.end());

        long long sum = v[v.size()-1] + v[v.size()-2];

        ans.push_back(sum);

        t--;
    }

    for(auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}