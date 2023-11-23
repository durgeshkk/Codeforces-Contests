
#include<bits/stdc++.h>
using namespace std;

int solve(string s)
{
 /*
    map<char,int> mp;
    for(int i = 0;i<26;++i){
        mp['a'+i] = 0;
    }

    // cout<<str<<endl;

    for(int i = 0;i<str.size();++i){
        if(str[i] == ' '){
            continue;
        }
        else{
            char c = tolower(str[i]);
            mp[c]++;
        }
    }

    for(auto it:mp){
        if(it.second == 0){
            // cout<<it.first<<endl;
            return 0;            
        }
    }
    return 1;*/

    int mx = 0;
    int n = s.size();

    set<char> st;
/*
    for(int i = 0;i<n;++i){
        if(st.find(s[i]) == st.end()){
            st.insert(s[i]);
        }
        else{
            mx = max(mx,st.size());
        }
    }*/

    int l = 0,r = -1;
    for(int i = 0;i<n;++i){
        if(st.find(s[i]) == st.end()){
            ++r;
            st.insert(s[i]);
            mx = max(mx,r-l);
        }
        else{
            for(int j = l;j<r;++j){
                if(s[l] == s[r]){
                    st.find(st.erase(s[r]));
                    break;
                }
                else{
                    st.find(st.erase(s[l]));
                    ++l;
                }
            }
        }
        cout<<l<<" "<<r<<endl;
    }

    return mx;
}
 
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        int ans = solve(str);
        cout<<ans<<endl;
    }
   return 0;
}