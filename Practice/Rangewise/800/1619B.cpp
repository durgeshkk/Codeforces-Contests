#include<bits/stdc++.h>
using namespace std;

void solve(){

    // long long size;
    // cin>>size;

    long long n;
    cin>>n;

    vector<long long> sq;
    vector<long long> cube;


    for(long long i=1;i<=n;i++){
        if((i*i) <= n){
            sq.push_back(i*i);
        }
        else{
            break;
        }
    }

    for(long long i=1;i<=n;i++){
        if((i*i*i) <= n){
            cube.push_back(i*i*i);
        }
        else{
            break;
        }
    }

    set<long long>s;
    for(long long i=0;i<sq.size();i++){
        s.insert(sq[i]);
    }

    for(long long i=0;i<cube.size();i++){
        s.insert(cube[i]);
    }

    // long long int count = s.size();
    // cout<<count<<endl;
    cout<<s.size()<<endl;

    return;
}

int main()
{
    int t;
    cin>>t;

    while(t != 0){
        solve();
        t--;
    }

    return 0;
}