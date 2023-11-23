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
 
    ll k;
    cin>>k;
    ll n,m;
    cin>>n>>m;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }
    
    vector<ll> v2(m);
    for(ll i=0;i<m;i++){
       cin>>v2[i];
    }

    // for(ll i=0;i<m;i++){
    //    cout<<v2[i]<<" ";
    // }
    // cout<<endl;

    vector<ll> ans(n+m);

    ll i = 0,j = 0,z=0;
    while((i<n) && (j<m)){
        if(v[i] == 0){
            ans[z] = 0;
            i++,k++;
            z++;
            continue;
        }

        if(v2[j] == 0){
            ans[z] = 0;
            j++,k++,z++;
            continue;
        }

        if(v[i] > v2[j]){
            if(k >= v2[j]){
                ans[z] = (v2[j]);
                z++;
                j++;
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
        else{
            if(k >= v[i]){
                ans[z] = (v[i]);
                z++;
                i++;
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
    }

    while(i<n){
        if(v[i] == 0){
            ans[z] = (0);
            i++,k++;
            z++;
            continue;
        }

        if(k >= v[i]){
            ans[z] = (v[i]);
            z++;
            i++;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }

    while(j<m){

        if(v2[j] == 0){
            j++,k++;
            ans[z] = (0);
            z++;
            continue;
        }

        if(k >= v2[j]){
            ans[z] = (v2[j]);
            j++;
            z++;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }

    for(ll i = 0;i<(n+m);i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

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