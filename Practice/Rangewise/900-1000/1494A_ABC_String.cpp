#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    string s;
    cin>>s;

    char x = s[0];
    char y,z;

    if(x == 'A'){
        y='B';
        z='C';
    }
    else if(x == 'B'){
        y='C';
        z='A';
    }
    else{
        x = 'C';
        y ='A';
        z ='B';
    }

    ll cx=0,cy=0,cz=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == x){
            cx++;
        }
        else if(s[i] == y){
            cy++;
        }
        else if(s[i] == z){
            cz++;
        }
    }

    ll diff=0;
    if(cx == (cy+cz)){
        for(int i=0;i<s.length();i++){
            if(diff >=0){
                if(s[i] == x){
                    diff++;
                }
                else if((s[i] == y || s[i] == z)){
                    diff--;
                }
            }
            else{
                cout<<"NO\n";
                return;
            }
        }  

        if(diff == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
    else if(cx+cy == cz){
        for(int i=0;i<s.length();i++){
            if(diff >=0){
                if(s[i] == x || s[i] == y){
                    diff++;
                }
                else if((s[i] == z)){
                    diff--;
                }
            }
            else{
                cout<<"NO\n";
                return;
            }
        }  

        if(diff == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
    else if(cx+cz == cy){
        for(int i=0;i<s.length();i++){
            if(diff >=0){
                if(s[i] == x || s[i] == z){
                    diff++;
                }
                else if((s[i] == y )){
                    diff--;
                }
            }
            else{
                cout<<"NO\n";
                return;
            }
        }  

        if(diff == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
    else{
        cout<<"NO\n";
    }

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}