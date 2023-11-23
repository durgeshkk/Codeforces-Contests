#include<bits/stdc++.h>
using namespace std;

void display(vector<long long> a,int n){
    for(int it = 0;it < n;it++){
        cout<<a[it]<<" ";
    }
    cout<<endl;
}


void solve(){
    
        int x1,x2,x3;
        int y1,y2,y3;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
                
        if(y1 == y2 || y2 == y3 || y3==y1){
            if((y1 == y2)&&(y3<y1)){
                cout<<abs(x2-x1)<<endl;
            }
            else if((y3 == y2)&&(y1<y2)){
                cout<<abs(x2-x3)<<endl;
            }
            else if((y1 == y3)&&(y2<y1)){
                cout<<abs(x3-x1)<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            cout<<0<<endl;
        }
        return;
}


int main()
{
    int t;
    cin>>t;

    while(t--){

        solve();
        // cout<<endl;
    }
    return 0;
}