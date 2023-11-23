#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
   string s;
   cin>>s;

    ll score = 0;

    if(s.length() == 1){
        cout<<"Bob "<<s[0]-96<<endl;
        return;
    }

   if(s.length()%2 != 0){
       if(s[0] > s[s.size()-1]){
           ll less = s[s.size()-1]-96;

            for(int i=0;i<s.length()-1;i++){
                score = score + (s[i]-96);
            }

            if(less > score){
                cout<<"Bob "<<less-score<<endl;
            }
            else{
                cout<<"Alice "<<abs(less-score)<<endl;
            }
       }
       else{

           ll less = s[0]-96;
            for(int i=1;i<s.length();i++){
                score = score + (s[i]-96);
            }

            if(less > score){
                cout<<"Bob "<<less-score<<endl;
            }
            else{
                cout<<"Alice "<<abs(less-score)<<endl;
            }
       }
   }
   else{
       for(int i=0;i<s.length();i++){
           score = score + (s[i]-96);
       }
       cout<<"Alice "<<score<<endl;
   }
//    cout<<score<<endl;
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
   //solve();
   return 0;
}