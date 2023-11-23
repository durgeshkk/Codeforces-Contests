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
       /*
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;*/

    if (n <= 3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
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
 
    ll n,e;
    cin>>n>>e;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    ll ans = 0;
    vector<ll> pr;

    for(ll i=0;i<n;++i){
        if(isPrime(v[i])){
            pr.push_back(i);
        }
    }

    for(ll i=0;i<pr.size();++i){
        ll l = pr[i]-e,r=pr[i]+e;
        ll a1 = 0,a2 = 0;

        while(l>=0 && v[l] == 1){
            l -= e;
            a1++;
        }
        
        while(r<n && v[r] == 1){
            r += e;
            a2++;
        }

        ans += ((a1*a2) + (a1+a2));
    }
    /*
        else if(v[i] == 1){
            f = 2;
        }

        if(f == 1){
            ll j = i;
            // for (int j = i; j <= n; j += k){
            while((j+e) < n){
                j += e;
                if(v[j] == 1){
                    ans++;
                }
                else{
                    break;
                }
            }
            
            f = 0;
        }
        else if(f == 2){
            
            ll j = i;
            ll t = 0;
            // for (int j = i; j <= n; j += k){
            while((j+e) < n){
                j += e;
                if(v[j] == 1){
                    if(t == 1){
                        ans++;
                    }
                }
                else if(s.find(j) != s.end()){
                    t++;
                    if(t==2){
                        break;
                    }
                    ans++;
                }
                else{
                    break;
                }
            }
            
            f = 0;
        }
    }*/
    cout<< ans<< endl;
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