#include<bits/stdc++.h>
using namespace std;

int maximise(vector<int> &v){
    sort(v.begin(),v.end());

    auto i = v.begin();
    auto j = v.begin()+1;
    for (i; i != (v.end()-2); i++)
    {
        j++;
    }

    return (*i)+(*j);
}

int main()
{
    int t;
    cin>>t;

    int ind = 0;
    int ans[t];

    while(t != 0){

        vector<int> v;
        int size;
        cin>>size;

        int weight;
        for(int i=0;i<size;i++){
            cin>>weight;
            v.push_back(weight);
        }

        ans[ind] = maximise(v);
        ind++;
        t--;
    }

    for(auto it:ans){
        cout<<it<<endl;
    }
    
    return 0;
}