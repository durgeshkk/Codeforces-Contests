#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }

    ll b;
    cin>>b;
    vector<ll> blue;
    for(ll i=0;i<b;i++){
       ll ele;
       cin>>ele;
       blue.push_back(ele);
    }

    ll s1 = accumulate(v.begin(),v.end(),0);
    ll s2 = accumulate(blue.begin(),blue.end(),0);

    ll i=0,j=0;
    ll mx = 0,s=0;

    if(v[0] > blue[0]){
        s += v[0];
        s1 -= v[i];
        i++;

        if(mx<s){
            mx = s;
        }
    }
    else{
        s += blue[0];
        s2 -= blue[j];
        j++;

        if(mx<s){
            mx = s;
        }
    }

    while(i!=n && j!=b){
        if(v[i] > 0 && blue[j] > 0){
            if(v[i] > blue[j]){
                s += v[i];
                s1 -= v[i];
                i++;
            }
            else{
                s += blue[j];
                s2 -= blue[j];
                j++;
            }
            if(mx<s){
                mx = s;
            }
        }
        else if(v[i] > 0){
            s += v[i];
            s1 -= v[i];
            i++;

            if(mx<s){
                mx = s;
            }
        }
        else if(blue[j] > 0){
            s += blue[j];
            s2 -= blue[j];
            j++;

            if(mx<s){
                mx = s;
            }
        }
        else{

            if(s1>s2){
                s += v[i];
                s1 -= v[i];
                i++;
            }
            else{
                s += blue[j];
                s2 -= blue[j];
                j++;
            }

            if(mx<s){
                mx = s;
            }
        }
        // cout<<s<<" ";
    }

    while(i != n)
    {
        s += v[i];
        s1 -= v[i];
        i++;

        if(mx<s){
            mx = s;
        }
        // cout<<s<<" ";
    }

    while (j != b)
    {
        s += blue[j];
        s2 -= blue[j];
        j++;

        if(mx<s){
            mx = s;
        }
        // cout<<s<<" ";
    }
    
    cout<<mx<<endl;
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
   //solve();
   return 0;
}