#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll LCM(ll a,ll b){
    ll ans = (a*b)/__gcd(a,b);
    return ans;
}

void solve()
{
 
    string s1,s2;
    cin>>s1>>s2;

    if(s1.size() == s2.size()){
        if(s1 == s2){
            cout<<s1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        return;
    }
    /*
    else{
        // cout<<"HI\n";
        ll mn = min(s1.length(),s2.length());
        ll mx = max(s1.length(),s2.length());
        // cout<<mn<<" "<<mx<<endl;

        string smn,smx;
        
        if(mn == s1.length()){
            smn = s1;
            smx = s2;
        }
        else{
            smn = s2;
            smx = s1;
        }
        

        // cout<<smn<<" "<<smx<<endl;

        if(mx%mn == 0){
            // cout<<"HIhi\n";
            ll y = mx/mn;
            string sz = smn;
            for(ll i=0;i<(y-1);i++){
                smn += sz;
            }
            // cout<<smn<<" "<<smx<<endl;
        }
        else{
            ll req_s = mn*mx;

            string sz = smn;
            for(ll i = 0;i<(mx-1);i++){
                smn += sz;
            }

            string sza = smx;
            for(ll i = 0;i<(mn-1);i++){
                smx += sza;
            }
        }
        // cout<<smn<<" "<<smx<<endl;
        if(smn == smx){
            cout<<smx<<endl;
        }
        else{
            cout<<-1<<endl;
        }*/

/*
        // Approach 1:
        if(s1.size() > s2.size()){
            swap(s1,s2);
        }

        ll n = s1.size();
        ll m = s2.size();

        ll l = LCM(n,m);

        string ans = "";
        
        ll k=0;
        // Travel Circularly for Smaller string s1
        for(ll i=0;i<l;i++){
            ans += (char)s1[k];
            k++;
            k%=n;
        }
        
        // Travel Circularly for Larger string s1
        for(ll i=0;i<l;i++){
            if(ans[i] != s2[k]){
                cout<<-1<<endl;
                return;
            }
            k++;
            k%=m;
        }

        cout<<ans<<endl;*/

        if(s1.size() > s2.size()){
            swap(s1,s2);
        }

        ll n = s1.size();
        ll m = s2.size();

        string s=s1,t=s2;
        while(1){
            if(s.size() > t.size()){
                t += s2;
                m += s2.size();
            }
            else{
                s += s1;
                n += s1.size();
            }
            if(n == m){
                break;
            }
        }

        if(s == t){
            cout<<s<<endl;
        }
        else{
            cout<<-1<<endl;
        }

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