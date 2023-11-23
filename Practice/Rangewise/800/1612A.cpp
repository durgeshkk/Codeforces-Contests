#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll x1=0,y1=0;
    
    ll x2,y2;
    cin>>x2>>y2;
    // cout<<endl;
    ll x3=-1,y3=-1;

/*
    if(((x2%2 != 0) && (y2%2 == 0)) || ((y2%2 != 0) && (x2%2 == 0))){
        cout<<x3<<" "<<y3<<endl;
    }
    else{
        ll value = ((x2+y2)/2);
        for(ll i=0;i<=(value/2);i++){
            x3 = i;
            y3 = value-i;
            if((abs(x2-x3) + abs(y2-y3)) == value){
                cout<<x3<<" "<<y3<<endl;
                return;
            }
        }
        // cout<<-1<<" "<<-1<<endl;
    }
    return;*/

    if(((x2%2 != 0) && (y2%2 == 0)) || ((y2%2 != 0) && (x2%2 == 0))){
        cout<<x3<<" "<<y3<<endl;
    }
    else if(x2>y2){
        cout<<((x2+y2)/2)<<" "<<0<<endl;
    }
    else{
        cout<<0<<" "<<((x2+y2)/2)<<endl;

    }

}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}