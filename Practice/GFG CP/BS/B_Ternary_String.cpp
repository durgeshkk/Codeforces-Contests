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

bool verify(ll window[4]){
    if((window[0] == 0) && (window[1] >= 1)&&(window[2] >= 1)&&(window[3] >= 1) ){
        return true;
    }
    return false;
}

bool check(string s, ll mid){

    ll window[4] = {0,0,0,0};

    ll i = 0;
    for(i;i<mid;++i){
        window[s[i]-'0']++;
    }

    if(verify(window)){
        return true;
    }

    ll p = 0;
    for(i;i<s.size();++i){

        window[s[p]-'0']--;
        window[s[i]-'0']++;

        if(verify(window)){
            return true;
        }
        ++p;
    }

    return false;
}

ll bs(string s,ll n){
    ll low = 0,high = n;

    ll ans = 1e9;
    while(low <= high){
        ll mid = (low + high)/2;

        if(check(s,mid)){
            ans = min(ans,mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    if(ans == 1e9){
        ans = 0;
    }

    return ans;
}

void solve()
{

    string s;
    cin>>s;

    ll n = s.size();
/*
    ll l = 0,r = -1;
    map<char,ll> mp;
    for(ll i = 0;i<n;++i){
        if(s[i] == '1'){
            mp[s[i]]++;
        }
        else if(s[i] == '3'){
            mp[s[i]]++;
        }
        else if(s[i] == '2'){
            mp[s[i]]++;
        }

        if(mp.size() == 3){
            r = i;
            break;
        }
    }

    if(mp.size() <= 2){
        cout<<0<<endl;
        return;
    }

    ll ans = (r-l+1);

    for(ll i = l;r<n;++i){
        if(mp[s[l]] == 1){
            r++;
            if(s[r] == s[l]){
                mp[s[l]]--;
                l++;
            }
        }
        else{
            mp[s[l]]--;
            l++;
        }
        mp[s[r]]++;

        ans = min(ans,(r-l+1));
    }
*/
    
    ll ans = bs(s,n);
    cout<< ans << endl;
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