#include<bits/stdc++.h>
using namespace std;

int dist(int x,int y){
    int sqr = pow(x,2) + pow(y,2);
    // cout<<sqr<<" ";

    float f = sqrt(sqr);
    // cout<<f<<" "<<sqr<<" ";

    int a = pow((sqr),0.5);
    // cout<<a<<" "<<endl;

    if(x == 0 && y == 0){
        return 0;
    }
    else if(f == a){
        return 1;
    }
    else{
        return 2;
    }
}

int main()
{
    // /*
    int t;
    cin>>t; 

    int a[t];
    int ind=0;
    while(t != 0){
        int x,y;
        cin>>x>>y;
        a[ind] = dist(x,y);
        ind++;
        t--;
    }

    for(int i=0;i<ind;i++){
        cout<<a[i]<<endl;
    }
    // */
/*

    int aq = (pow(8,2) + pow(6,2));
    float f = sqrt(aq);
    int a = pow((aq),0.5);

    if(f == a){
        cout<<"y\n";
    }
    else{
        cout<<"ny\n";
    }
    cout<<f<<" "<<a<<endl;
    */
    return 0;
}