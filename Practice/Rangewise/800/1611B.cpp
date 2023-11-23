#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    // ll n;
    // cin>>n;

    ll pro,maths;
    cin>>pro>>maths;

    ll sum = (pro+maths);
    ll teams = sum/4;

    ll min_ele = min(pro,maths);

    if(teams >= min_ele){
        cout<<min_ele<<endl;
    }
    else{
        cout<<teams<<endl;
    }
    return;
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