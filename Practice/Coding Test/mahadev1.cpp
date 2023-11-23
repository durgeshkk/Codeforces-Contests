#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;cin>>n;
    vector<int> arr1(n);
    for(int i = 0;i<n;++i){
        cin>>arr1[i];
    }

    int mx = 0,cnt = 1;
    for(int i = 0;i<n-1;++i){
        if(arr1[i] == arr1[i+1]){
            ++cnt;
        }else{
            cnt = 1;
        }
        mx = max(mx,cnt);
    }
    cout<<mx<<endl;
    return;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   solve();
   return 0;
}
// Q2
/*
void solve()
{
    int n;cin>>n;
    vector<char> arr1(n),arr2(n);
    for(int i = 0;i<n;++i){
        cin>>arr1[i];
    }
    for(int i = 0;i<n;++i){
        cin>>arr2[i];
    }
    
    for(int i = 0;i<n;++i){
        char c = arr1[i];
        int f = 0,idx;
        for(int j = 0;j<n;++j){
            if(arr2[j] == c){
                f = 1;
                idx = j;
            }
        }
        if(f & 1){
            cout<<c<<" - ";
            cout<<idx<<endl;
        }else{
            cout<<c<<" - ";
            cout<<"NA\n";
        }
    }
    return;
}
 */
