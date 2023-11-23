#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            count++;
            else count--;
        }

        if(count!=0){
            cout<<"-1"<<endl;
            continue;
        }

        int c=0;
        int zc=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')zc++;
            else zc--;
            if(zc<0)
            {c++;
            break;}
        }
        zc=0;

        for(int i=0;i<n;i++){
            if(s[i]==')')zc++;
            else zc--;
            if(zc<0)
            {c++;
            break;}
        }
        if(c<2){
            cout<<1<<endl;
            while(n--)cout<<1<<' ';
            cout<<endl;
        }else{
            int col[n];
            int i=0;
            int j=n-1;
            while(i<j){
                if(s[i]==')' && s[j]==')'){
                    col[i++]=2;
                    col[j--]=1;
                }
                else if(s[i]=='(' && s[j]=='('){
                    col[i++]=1;
                    col[j--]=2;
                }
                else if(s[i]==')' && s[j]=='('){
                    col[j--]=2;
                    col[i++]=2;
                }else{        
                    col[i++]=1;
                    col[j--]=1;
                }
                
                
            }
            cout<<"2"<<endl;
            for(int i=0;i<n;i++)
            cout<<col[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}