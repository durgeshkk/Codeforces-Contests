#include<bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);


ll recur(ll i,ll j,string s,string s1,string s2,ll f){
    if(i > j){
        // Check for Small string & return
        if(s1 == s2){
            return 1;
        }
        return 0;
    }

    // Alice Chance
    bool a = false,b = false;
    bool c = false,d = false;
    if(f == 0){
        // Alice aa khel
        // Picks 1st char
        string s4;s4 += s[i];s4 += s1;
        a = recur(i+1,j,s,s4,s2,1);
        
        // Picks last char
        string s5;s5 += s[j];s5 += s1;
        b = recur(i,j-1,s,s5,s2,1);
    }else{
        // Bob aa khel
        // Picks 1st char
        string s4;s4 += s[i];s4 += s2;
        c = recur(i+1,j,s,s1,s4,0);

        // Picks last char
        string s5;s5 += s[j];s5 += s2;
        d = recur(i,j-1,s,s1,s5,0);
    }

    bool e = (a|b|c|d);
    return e;
}

vector<vector<ll>> dp;
ll helper(ll i,ll j,string &s){
    // 1 : Alice Wins
    // 0 : Draw

    // dp[i][j] : Winners of Subarray starting from i to j !!
    if(i > j){
        return 0;
    }

    // Alice winnings!!
    if((s[i] != s[j]) and ((s[i] != s[i+1]) || (s[j-1] != s[j]))){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // Draw pssbl:
    ll ans = 0;
    // Alice picks i & j is also the same
    if(s[i] == s[j]){
        ans = ans | (helper(i+1,j-1,s));
        return ans;
    }

    // Alice picks i & i+1 is also the same
    if(s[i] == s[i+1]){
        ans = ans | (helper(i+2,j,s));
    }
    
    // Alice picks j-1 & j is also the same
    if(s[j-1] == s[j]){
        ans = ans | (helper(i,j-2,s));
    }

    return dp[i][j] = ans;
}

void solve()
{
 
    string s;cin>>s;
    ll n = s.size();
    dp.assign(n+5,vector<ll> (n+5,-1));


    // n^2 implies ans is smnthng related to subarray!!
    ll b = helper(0,n-1,s);
    if(b & 1){
        cout<<"Alice\n";
    }else{
        cout<<"Draw\n";
    }

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}