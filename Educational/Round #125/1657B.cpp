#include<bits/stdc++.h>
using namespace std;

long long maxsum(long long n,long long B,long long x,long long y){
    long long sum = 0,prev = 0, num = 0;

    while(n != 0){

        long long a = prev + x;
        long long b = prev - y;
        
        if((B>=a)){
            num = prev + x;
            prev = num;
            sum += num;
        }


        // while((B<num)){
        else{
            num = prev - y;
            prev = num;
            sum += num;
        }

        n--;
    }

    return sum;
}

int main()
{
    int t;
    cin>>t; 

    long long a[t];
    int ind=0;
    while(t != 0){
        long long n,B,x,y;
        cin>>n>>B>>x>>y;
        a[ind] = maxsum(n,B,x,y);
        ind++;
        t--;
    }

    for(int i=0;i<ind;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}