#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    vector<long long> ans;
    
    while(t != 0){

        long long n;
        cin>>n;

        long long sum;
        cin>>sum;

        vector<long long> v;
/*
        for(int i =0;i<size;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
        }
*/
        long long n2 = n*n;
        long long int val = sum/n2;
        // long long rem_sum = sum - (val*n2);

        // n = n-val+1;

        // if((val > 0) && (n >= rem_sum)){
        // if((val > 0) && (n >= rem_sum)){
            ans.push_back(val);
        // }
        // else{
            // ans.push_back(0);
        // }
        t--;
    }

    for(auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}