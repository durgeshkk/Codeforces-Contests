#include<bits/stdc++.h>
using namespace std;


// Question says 1st jo no apne jagah pe nhi h wahan se leke toh wo no. jahan kahi tak bhi 
// h utne array ke part ko reverse karo
// e.g. 1 4 6 2 3 5 --> reverse 4 to 2 since 2 must be at ind 1
//      1 2 6 4 3 5(expected output)
void solve(){
        long long size;
        cin>>size;

        vector<long long> v;

        for(int i=0;i<size;i++){
            long long ele;
            cin>>ele;
            v.push_back(ele);
        }

        int ind=0;
        // vector<long long>::iterator actual_present;
        int actual_present=0;
        while(ind<size){
            if((ind+1)==v[ind]){
                ind++;
            }
            else{
                // actual_present = find(v.begin(),v.end(),ind+1);
                
                /*
                for(int j=ind+1;j<size;j++){
                    if((ind+1)==v[j]){
                        actual_present = j;
                        break;
                    }
                }*/
                break;
            }
        }
        if(ind == size){

        }
        else{
            reverse(v.begin()+ind,v.begin()+(actual_present+1));
        }

        for(auto in:v){
            cout<<in<<" ";
        }
        cout<<endl;
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