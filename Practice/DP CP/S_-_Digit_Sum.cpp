#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
 
/*
***     DIGIT DP    ***

    So, any i from [1,R] can stored in form of sequence of digit/array/string 
    Array is preferred mostly for int to avoid conversions!!
    e.g. R = 1234566712345667...
    int R[10001] = {1,2,3,4,5,6,6,7,..}

    To find the no. smaller than R, we need to use DP ,
    States we need are : Pos,flag
    flag to check ki abb tk jo bhi pos tak aye h wahan tk no. small hua h ya nhi
    Agar ho gya toh aage we can add any no. it will always be small Doesn't matter:
    e.g. R = 1234567 ==> smaller check at pos = 5,
         z = 1233999        flag at pos = 2(0 based idx) is set to 0{since no. r ==}
         z = 1233999        flag at pos = 3(0 based idx) is set to 1{we made no. small}

    Acc to given Q we might need to store some more states
    In this Q, the more req. state will be (sum_of_dig % 99), since D<=100

    So normal sol : 9e(1e4)
    By DP : pos*flag*sod = 1e4*2*100 = 2e6
*/

ll dp[10004][2][100];
string s;
ll d;
ll recur(ll pos,ll f,ll sm){
    if(pos >= s.size()){
        if(sm == 0){return 1;}
        return 0;
    }

    ll &smallans = dp[pos][f][sm];
    if(smallans != -1){
        return smallans;
    }

    smallans = 0;
    if(f & 1){
        for(ll i = 0;i<10;++i){
            smallans = mod_add(smallans,recur(pos+1,1,(sm+i)%d),mod);
        }
    }else{
        for(ll i = 0;i<10;++i){
            if(i > (s[pos]-'0')){break;}
            else if(i == (s[pos]-'0') ){
                smallans = mod_add(smallans,recur(pos+1,0,(sm+i)%d),mod);
            }else{
                smallans = mod_add(smallans,recur(pos+1,1,(sm+i)%d),mod);
            }
        }
    }
    return dp[pos][f][sm] = smallans;
}

ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

void solve()
{
 
    cin>>s;
    // k can have 1e(1e4) so don't think of iterating
    cin>>d;
    for(ll i = 0;i<=s.size();++i){
        for(ll j = 0;j<=99;++j){
            dp[i][0][j] = -1;
            dp[i][1][j] = -1;
        }
    }

    ll ans = mod_sub(recur(0,0,0),1,mod);
    cout<<ans<<endl;
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}
