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

        vector<string> v;

        int fr=0,fg=0,fb=0;

        for(int i=0;i<s.size();i++){
            if(s[i] == 'r'){
                fr=1;
            }
            else if(s[i] == 'g'){
                fg=1;
            }
            else if(s[i] == 'b'){
                fb=1;
            }
            else if(s[i] == 'B' && fb==1){
                fb=0;
            }
            else if(s[i] == 'G' && fg==1){
                fg=0;
            }
            else if(s[i] == 'R' && fr==1){
                fr=0;
            }        
            else{
                fb=fg=fr=-1;
                break;
            }    
        }

        if(fg==0 && fb==0 && fr==0){
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