#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    string s;
    cin>>s;

    ll sab=0;
    ll sba=0;
    ll sa=0;
    ll sb=0;

    if(s.size() == 1){
        cout<<s<<endl;
        return;
    }
    /*
    string snew;

    int i=0;
    while(i < s.size()-1){
        if(s[i] == 'a' && s[i+1]=='b'){
            sab++;
        }
        else if(s[i] == 'b' && s[i+1]=='a'){
            sba++;
        }
        if(s[i] == 'a'){
            sa++;
        }
        else if(s[i] == 'b'){
            sb++;
        }
        i++;
    }

    if(s[i] == 'a'){
        sa++;
    }
    if(s[i] == 'b'){
        sb++;
    }
    i++;

    if(sab == sba){
        cout<<s<<endl;
        return;
    }

    if(sa == 1){
        i=0;
        while(i < s.size()){
            if(s[i] == 'a'){
                s[i] = 'b';
            }
            i++;
        }
        snew = s;
    }

    else if(sb == 1){
        i=0;
        while(i < s.size()){
            if(s[i] == 'b'){
                s[i] = 'a';
            }
            i++;
        }
        snew = s;
    }

    else{
        while(sb > 0){
            snew += 'b';
            sb--;
        }
        while(sa > 0){
            if(sa >= 2){
                snew = 'a'+snew+'a';
                sa -= 2;
            }
            else{
                snew += 'a';
                sa--;
            }
        }
    }

    cout<<snew<<endl;*/

// If 1st & last same means same no. of ab & ba always
    if(s[0] == s[s.size()-1]){
        cout<<s<<endl;
    }
// If not then either make 1st same as last char or vice versa
    else{
        // Skip last & print s[0]
        cout<<s.substr(0,s.length()-1)<<s[0]<<endl;
    }
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