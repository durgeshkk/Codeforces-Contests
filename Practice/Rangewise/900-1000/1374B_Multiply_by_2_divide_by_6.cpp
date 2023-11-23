#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    if(n==1){
        cout<<0<<endl;
        return;
    }

    else if(n==3){
        cout<<2<<endl;
        return;
    }

    ll nit = n%6;
    if(nit == 2 || nit == 4 || nit == 5){
        // cout<<"HI tum\n";
        cout<<-1<<endl;
        return;
    }

    if(n%2 == 0 || n%3 == 0){
        ll num = n;
        ll count_3 = 0;
        ll count_2 = 0;

        while(num%3 == 0 && num != 1){
            count_3++;
            num /= 3;
        }

        ll num2 = num;
        while(num2%2 == 0 && num2 != 1){
            count_2++;
            num2 /= 2;
        }

        // cout<<count_2<<" "<<count_3<<endl;
        if(num2 != 1 || (count_2>count_3)){
            // cout<<"HI\n";
            cout<<-1<<endl;
            return;
        }
        else{
            cout<<2*count_3-count_2<<endl;
        }
    }   
    else{
        cout<<-1<<endl;
    }
    
    /*while(n != 1){

        ll num = n/6;
        ll rem = n%6;

        if(num == 1){
            cout<<n/6<<endl;
            return;
        }

        if(num == 2 || num == 4 || num == 5){
            cout<<-1<<endl;
        }
        else if(num == 3){
            // cout<<-1<<endl;
            ll ans = n*2;
            ll count = ans/6;
            cout<<count+1<<endl;//1 for *2
        }
        n = n/6;
    }*/
    /*
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }*/
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
       solve();
   }
   return 0;
}