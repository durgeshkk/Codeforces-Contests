#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    string s;
    cin>>s;
/*
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i] == '0' || s[i] == '2'){
            st.push(s[i]);
        }
    }

    string new_s;
    while(!st.empty()){
        new_s += st.top();
        st.pop();
    }

    ll idx = new_s.find("0202");
    if(idx != 0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }   */
/*
    ll idx = s.find("2020");
    if(idx < n && (idx >= 0)){
        cout<<"YES"<<endl;
        return;
    }

    if(s[0] == '2' && s[s.size()-3] == '0' 
    && s[s.size()-2] == '2' && s[s.size()-1] == '0'){
        cout<<"YES"<<endl;
    }
    else if(s[0] == '2' && s[1] == '0' 
    && s[s.size()-2] == '2' && s[s.size()-1] == '0'){
        cout<<"YES"<<endl;
    }
    else if(s[0] == '2' && s[1] == '0' 
    && s[2] == '2' && s[s.size()-1] == '0'){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
*/

    for(int i=0;i<=4;i++){
        string t1 = s.substr(0,i);
        string t2 = s.substr(n-4+i,4-i);
        string ans = t1+t2;
        if(ans == "2020"){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}