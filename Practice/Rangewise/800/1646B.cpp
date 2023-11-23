#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    vector<string> ans;
    
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

        int countB = (size+1)/2;
        long long sumB = 0,sumR = 0;

        int i=0;
        while(i < countB){
            sumB += v[i];
            i++;
        }

        if(size%2 == 0){
            int j=i+1;
            while(j < v.size()){
                sumR += v[j];
                j++;
            }
        }
        else{
            int j=i;
            while(j < v.size()){
                sumR += v[j];
                j++;
            }
        }

        if(sumR > sumB){
            ans.push_back("Yes");
        }
        else{
            ans.push_back("No");
        }

        t--;
    }

    for(auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}