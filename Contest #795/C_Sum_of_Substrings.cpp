#include<bits/stdc++.h>
#include<iomanip>
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
 
    ll n,k;
    cin>>n>>k;

    string st;
    cin>>st;

    vector<ll> v;
    ll idx = -1;
    ll flag = 0;

    for (ll i=0;i<n;++i){
        if (st[i] == '1'){
            v.push_back(i);
        }
    }

    if (v.size() == 0){
        cout<<"0"<<endl;
        return;
    }
    else if (st[n-1]=='1'){
        flag = 1;
    }

    if (st[n-1] == '0'){
        if ((n-(v[v.size()-1])-1) <= k){
            flag = 1;
            st[n-1]='1';
            k = (k-(n-(v[v.size()-1])-1));

            ll ft = 0;
            for (ll tt =n-2;tt>=0;--tt){
                if (st[tt] == '1'){
                    st[tt] = '0';
                    ft = 1;
                }

                if(ft == 1){
                    break;
                }
                else{
                    continue;
                }
            }
        }
    }

    if (st[0] == '0'){
        if ((v.size()==1)&&(flag == 1)){
            
        }
        else if (v[0] <= k){
            st[0] = '1';

            for (ll dk=1;dk<n;++dk){
                if (st[dk]=='1'){
                    st[dk]='0';
                    break;
                }
            }
        }
    }

    ll cnt = 0;
    for (ll k = 0;k<n-1;++k){
        string zee = st.substr(k,2);
        ll z = stoll(zee);
        cnt += z;
    }
    cout<<cnt<<endl;

/*

    for(ll i = 0;i<n;++i){
        if(s[i] == '1'){
            if(f==0){
                idx = i;
            }
            f = 1;
        }
        else if(f == 1 && s[i] == '0'){
            v.push_back(i);
        }
    }

    for(ll i =0;i<v.size();++i){
        v[i] = (v[i]-idx-i);
    }

    for(ll i =0;i<v.size();++i){
        if(k > v[i]){
            k -= v[i];
        }
    }*/
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}