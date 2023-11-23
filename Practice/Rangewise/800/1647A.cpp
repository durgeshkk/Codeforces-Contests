#include<bits/stdc++.h>
using namespace std;

void solve(){
        long long n;
        cin>>n;

        vector<long long> v;
        long long div = n/3;
        long long rem = n%3;

        if(rem == 0){
            while(div != 0){
                v.push_back(2);
                v.push_back(1);
                div--;
            }
        }
        else if(rem == 1){
            while(div != 0){
                v.push_back(1);
                v.push_back(2);
                div--;
            }
            v.push_back(1);
        }
        else if(rem == 2){
            while(div != 0){
                v.push_back(2);
                v.push_back(1);
                div--;
            }
            v.push_back(2);
        }

        for(auto it:v){
            cout<<it<<"";
        }
        cout<<endl;

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