#include<bits/stdc++.h>
using namespace std;

int recur(vector<int> v){

    int sum = accumulate(v.begin(),v.end(),0);
    // cout<<sum<<endl;
    int to_remove = v.front();
    int prev = v.front();

    while(v.size() != 1){
        to_remove = v.front();
        sum = sum - (v.size()*to_remove);
        v.pop_back();
        prev = v.front();
        v[0] = v[0] - to_remove;
    } 

    return sum;
}

int recursion(vector<int> v){
    // int sum = sum - (v.size()*to_remove);
    if(v.size() == 1){
        return v[0];
    }

    int first = v.front();
    v.pop_back();

    for(int i=0;i<v.size();i++){
        if(v[0] == 0){
            break;
        }
        v[i] -= first;
    }

    return recursion(v);
}


int main()
{
    int t;
    cin>>t;
    
    vector<string> v;

    while(t != 0){
        int len;
        cin>>len;

        int k;
        cin>>k;

        vector<int> v1;

        for(int i=0;i < len;i++){
            int ele;
            cin>>ele;
            v1.push_back(ele);
        }

        if(k == recursion(v1)){
            v.push_back("Yes");
        }
        else{
            v.push_back("No");
        }
        t--;
    }

    for(auto it:v){
        cout<<it<<endl;
    }   
    
    return 0;
}