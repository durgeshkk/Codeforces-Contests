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
 
void solve()
{
 
    ll n;
    cin>>n;
    
    ll a,b;
    cin>>a>>b;

    string s;
    cin>>s;
/*
    if(a < b){
        cout<<s.size()*(b-a)<<endl;
    }
    else{

    }*/

    ll max = a*1 + b;
    

    ll ans = a*n;
    if(b > 0){
        cout<<ans+b*n<<endl;
        return;
    }
    else{
        int total=0;
        for(ll i=1;i<s.size();i++){
            if(s[i] != s[i-1]){
                total++;
            }
        }    
        total++;
        ans += ((total/2)+1)*b;//deleting alternate "111.." grps & 
        // lastly all 0 will be deleted at once thus,+1 
    }

    cout<<ans<<endl;
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