#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    string s;
    cin>>s;

    int i=0;
    int f0=0,f1=0;
    if(s[0] == '0'){
        f0 = 1;
    }
    else{
        f1 = 1;
    }
    
    while(i<(s.size()-1)){
        if(s[i] == '0' && s[i+1]=='0'){
            f0++;
        }
        else if(s[i] == '1' && s[i+1]=='1'){
            f1++;
        }
        else if(s[i] == '0' && s[i+1]=='1'){
            f0=0;
            f1=1;
        }
        else if(s[i] == '1' && s[i+1]=='0'){
            f1=0;
            f0=1;
        }

        if((f0>=7) || (f1>=7)){
            cout<<"YES\n";
            return;
        }
        i++;
    }
    cout<<"NO\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
//    cin >> t;
//    while (t--)
//    {
       solve();
//    }
   return 0;
}