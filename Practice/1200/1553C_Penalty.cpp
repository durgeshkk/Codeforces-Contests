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

ll help(ll idx,ll f,ll s,ll k1,ll k2,string s1){//f = first team goals dn
// k1 : chances left to score goal/kicks left
    if(idx == 10){//reached last idx
        return 0;//simply return 0
    }

    if(f+k1 < s){ 
// goals scored+kick left is less than goals scored by team 2 thus team 2 wins ultimately
        return 0;//no more penalty shoots left
    }
    
    if(s+k2 < f){
        return 0;
    }

    if(s1[idx] == '1'){
        if(idx%2 == 0){//even idx of 1st team
            f++;//goal scored
            k1--;//kicks left
        }
        else{// odd idx for 2nd team
            s++;
            k2--;
        }

        return 1+help(idx+1,f,s,k1,k2,s1);
    }
    else if(s1[idx] == '0'){
        if(idx%2 == 0){
            k1--;
        }
        else{
            k2--;
        }

        return 1+help(idx+1,f,s,k1,k2,s1);
    }
    else{//'?' found 
        if(idx%2 == 0){
// Try both cases goal scored as well as kicks left
            return 1+min(help(idx+1,f+1,s,k1-1,k2,s1),help(idx+1,f,s,k1-1,k2,s1));
        }
        else{
// Try both cases goal scored as well as kicks left
            return 1+min(help(idx+1,f,s+1,k1,k2-1,s1),help(idx+1,f,s,k1,k2-1,s1));
        }
    }
}


void solve()
{
 
    // ll n;
    // cin>>n;
    
    string s;
    cin>>s;
/*
    string t1,t2;

    ll ans = 9;
    for(ll i = 0;i<s.size();i+=2){
        t1 += s[i];
        t2 += s[i+1];
    }

    ll t1w=0,t1q=0;
    ll t2w=0,t2q=0;

    ll j = 0;
    ll ans = 9;
    for(ll i = 0;i<t1.size();i++,j++){
        if(t1[i] == '1'){
            t1w++;
        }
        else if(t1[i] == '0'){
            // t1l++;
        }
        else{
            t1q++;
        }
        

        if(t2[i] == '1'){
            t2w++;
        }
        else if(t1[i] == '0'){
            // t1l++;
        }
        else{
            t2q++;
        }

        ll w = abs((t1w+t1q)-(t2w+t2q));


        if(t1w >= t2w){
            w = abs(t1w-t2w);
        }

    }*/

    cout<<help(0,0,0,5,5,s);
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