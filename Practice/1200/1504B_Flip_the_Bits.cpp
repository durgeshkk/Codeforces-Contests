#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}
void solve()
{
 
    ll n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;
/*
    if( s1 == s2){
        cout<<"YES\n";
        return;
    }

    if(n == 1){
        cout<<"NO\n";
        return;
    }

    ll j = (n-1);
    ll f = 0;
    ll co=0,cz=0,clz=0,clo=0;

    for(j;j>=0;j--){
        if(s1[j] != s2[j]){
            if(s1[j] == '1'){
                co++;
            }
            else{
                cz++;
            }
            f = 1;
            clo = 0,clz=0;
        }

        else if(s1[j] == s2[j]){
            // cout<<j<<endl;
            // cout<<j<<" 0 :"<<s1[0]<<" "<<s2[0]<<endl;
            if(co != cz){
                cout<<"NO\n";
                return;
            }
            co = 0,cz=0;

            // if(f == 1){
                if(s1[j] == '0'){
                    // cout<<j<<" "<<s1[j]<<endl;
                    clz++;
                }
                else{
                    clo++;
                }
            // }
            f = 0;
        }
    }

    // cout<<j<<endl;
    // cout<<clo<<" "<<clz<<endl;
    
    if((co != cz) || (clo != clz)){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";*/

    int one=0;
    int zero=0;
    vector<pair<int,int>>x;
    int j=0;
    for(int i=0;i<n;i++){
        if(s1[i]=='1') one++;
        else zero++;
        if(one == zero){
            x.push_back({j,i});
            j=i+1;
        }
    }
    
    for(auto i : x){
        int start=i.first;
        int end=i.second;
        if(s1[start]==s2[start])
        {
            continue;
        } 
        else{
            for(int j=start;j<=end;j++){
                if(s1[j]=='0') {
                    s1[j]='1';
                }
                else
                {
                    s1[j]='0';
                } 
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            cout<<"NO"<<"\n";
            return;
        }
    }

    cout<<"YES"<<"\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}