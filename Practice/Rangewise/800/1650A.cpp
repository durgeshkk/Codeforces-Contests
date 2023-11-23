#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    vector<string> ans;
    
    while(t != 0){

        string s;
        cin>>s;

        char find_char;
        cin>>find_char;

        vector<string> v;
/*
        for(int i =0;i<size;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
        }
*/
        int ind=-1;
        for(int i=0;i<s.size();i++){
            if(s[i] == find_char && i%2 == 0){
                ind = i;
                break;
            }
        }

        if(ind%2 == 0 && s[ind] == find_char){
            ans.push_back("YES");
        }
        else{
            ans.push_back("NO");
        }
        t--;
    }

    for(auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}