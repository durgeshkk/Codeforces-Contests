#include<bits/stdc++.h>
using namespace std;

void solve(){
        string s;
        cin>>s;

        map<char,int> mp;
        int i=0;
        while(i != s.size()){
            mp[s[i]]++;
            i++;
        }

        for(int ind=0;ind<s.size();ind++){
        
            if(mp[s[ind]]==1){
                for(int i=ind;i<s.size();i++){
                    cout<<s[i];
                }
                return;
            }

            mp[s[ind]]--;
        }
}


int main()
{
    int t;
    cin>>t;

    while(t--){

        solve();
        cout<<endl;
    }
    return 0;
}