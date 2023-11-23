#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    vector<pair<int,int>> v;

    while(t != 0){
        int n;
        cin>>n;

        vector<int> v1;

        for(int i=0;i<n;i++){
            int ele;
            cin>>ele;
            v1.push_back(ele);
        }

        int ind_low=1,ind_up=1;
        int min = INT16_MAX;
        int max = INT16_MIN;
        for(int i=0;i < v1.size();i++){
            if(max < v1[i]){
                ind_up = i+1;
                max = v1[i];
            }
            else if(min > v1[i]){
                ind_low = i+1;
                min = v1[i];
            }
        }

        pair<int,int> p;
        p.first = ind_low;
        p.second = ind_up;

        v.push_back(p);
        t--;
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    
    return 0;
}