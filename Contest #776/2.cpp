#include<iostream>
using namespace std;

long final(long l,long r,long a){
    long ans[r-l+1];
    long ind = 0; 

    for (long i = l; i <= r; i++)
    {
        long b = long(i/a) + (i%a);
        ans[i-l] = b;
    }

    long max = ans[0];  
    for (long i = 1; i <= r-l; i++)
    {
        if(ans[i] > max){
            max = ans[i];
            ind = i+l;
        }
    }

    return ans[ind-l];        
    // return max;        
}

int main(){
    int t;//no. of test cases
    cin>>t;
    long z[t];
    int i=0;
    while(t != 0){
        long l;
        cin>>l;
        long r;
        cin>>r;
        long a;
        cin>>a;

        z[i] = final(l,r,a);
        i++;
        t--;
    }

    for (int j = 0; j < i; j++)
    {
        cout<<z[j]<<endl;
    }

    return 0;
}