#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 


void solve(int n,int A[])
{
    int ans=0;

    int C[n];
    for(int i=0;i<n;i++){
        C[i]=A[i];
    }

    sort(C,C+n);

    int large = C[n-1];

    int B[n];
    B[0]=1;
    B[1]=1;
    int B_size=2;

    int i=2;
    while(i <= n){
        B[i] = B[i-1]+B[i-2];
        if(B[i] > large){
            break;
        }
        B_size++;
        i++;
    }
    /*

    map<int,int> mp;
    for(int i=0;i<B_size;i++){
        mp[B[i]]++;
    }

    for(int i=0;i<n;i++){
        if(mp[A[i]] >= 1){
            mp[A[i]]--;
            ans++;
        }
    }

    for(int i=0;i<mp.size();i++){
        if(mp[B[i]] != 0){
            cout<<0<<endl;
            return;
        }
    }
    cout<<ans<<endl;*/
    int j=0;
    for(int i=0;i<n;i++){
        if(B[j] == A[i]){
            ans++;
            j++;
        }
    }
    cout<<ans<<endl;
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
       int n;
        cin>>n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
       solve(n,arr);
   }
   return 0;
}