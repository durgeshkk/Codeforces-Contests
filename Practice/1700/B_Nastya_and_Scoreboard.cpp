#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
// Big two primes
#define X 1001100011100001111ll
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define int int
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define kitna se
#define endl "\n"
#define pii pair<int, int>
#define vii vector<pi>
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
void pr(int x) {cout << x;}
void prl(int x) {cout << x << endl;}
// typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;
//bool isPrime(int N){ for(int i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
int cbrt(int x) { int lo = 1, hi = min(2000000ll, x); while (hi - lo > 1) {int mid = (lo + hi) / 2; if (mid * mid * mid < x) {lo = mid;} else hi = mid;} if (hi * hi * hi <= x) return hi; else return lo;}
const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int N =  (int)(2 * 1e5 + 10);

int n, k;
vector<string>digit;
vector<string>cal;

int dp[2005][2005][11];

int changes[2005][10];
// vector<string>ans;

int compute(int ind, int sum, int num) {
    if (ind == n) {
        if (sum == 0) {
            return dp[ind][sum][num] = 1;
        }

        return dp[ind][sum][num] = 0;
    }

    if (sum < 0) return dp[ind][sum][num] = 0;

    if (dp[ind][sum][num] != -1) return dp[ind][sum][num];


    int maxi = 0;

    for (int i = 9; i >= 0; i--) {
        int cnt = changes[ind][i];
        char c = 48 + i;
        // cout << c << endl;
        if (cnt != -1 && cnt <= sum)
            maxi = max(maxi, compute(ind + 1, sum - cnt, i));
    }
    return dp[ind][sum][num] = maxi;
}


string ans = "";

void findans(int ind, int sum, int num)
{
    if (ind == n)
        return ;

    bloop(i, 9, 0)
    {
        int cnt = changes[ind][i];
        //cout << sum - cnt << " " << cnt << " " << dp[ind + 1][sum - cnt][i] << endl;
        if (sum - cnt >= 0 && cnt != -1 && dp[ind + 1][sum - cnt][i] == 1)
        {
            char c = i + 48;
            ans += c;
            // cout << "raj";
            findans(ind + 1, sum  - changes[ind][i], i);
            return ;
        }
    }
}



signed main() {

    fio;
//srand(time(NULL));
    int T = 1;
    // cin >> T;

    while (T--) {
        ini(dp, -1);

        for0(i, 10)
        digit.push_back("01111111");

        digit[0][4] = '0';

        digit[1][1] = '0';
        digit[1][2] = '0';
        digit[1][4] = '0';
        digit[1][5] = '0';
        digit[1][7] = '0';

        digit[2][2] = '0';
        digit[2][6] = '0';

        digit[3][2] = '0';
        digit[3][5] = '0';

        digit[4][1] = '0';
        digit[4][5] = '0';
        digit[4][7] = '0';

        digit[5][3] = '0';
        digit[5][5] = '0';

        digit[6][3] = '0';

        digit[7][2] = digit[7][4] = digit[7][5] = digit[7][7] = '0';

        digit[9][5] = '0';


        cin >> n >> k;

        for0(i, n)
        {
            string s;
            cin >> s;
            s = '0' + s;
            cal.push_back(s);
        }

        for (int ind = 0; ind < n; ind++) {
            for (int i = 9; i >= 0; i--) {
                int cnt = 0;
                string s1 = digit[i];
                string s2 = cal[ind];
                for1(j, 7) {
                    if (s1[j] == '1' && s2[j] == '0') {
                        cnt++;
                    }
                    else if (s1[j] == '0' && s2[j] == '1') {
                        cnt = -1;
                        break;
                    }
                }
                changes[ind][i] = cnt;
            }
        }



        int vall = compute(0, k, 0);
        // prl(vall);

        findans(0, k, 0);


        if (ans.size() == 0) prl(-1);
        else cout << ans;


    }
}




/*
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll n,k;
vector<string> p = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string ans;

vector<vector<ll>> dp;
ll dk[2005][2050][11];

ll dfs(ll i,ll cnt,ll pick){
    if(cnt > k){return 0;}

    if(i == n){
        if(cnt == k){
            return 1;
        }
        return 0;
    }


    ll &a = dk[i][cnt][pick];
    if(a != -1){return a;}
    a = 0;

    for(ll j = 9;j>=0;--j){
        if(dp[i][j] == -1){continue;}
        a |= dfs(i+1,cnt+dp[i][j],j);
    }
    return a;
}

void findans(int ind, int sum, int num)
{
    if (ind == n)
        return ;
 
    for(int i = 9;i>=0;--i){
        int cnt = dp[ind][i];
        //cout << sum - cnt << " " << cnt << " " << dp[ind + 1][sum - cnt][i] << endl;
        if (sum - cnt >= 0 && cnt != -1 && dk[ind + 1][sum - cnt][i] == 1)
        {
            char c = i + 48;
            ans += c;
            cout<<c;
            // cout << "raj";
            findans(ind + 1, sum  - dp[ind][i], i);
            return ;
        }
    }
}
 

void solve()
{
 
    cin>>n>>k;
    vector<string> v(n);enter(v);

    dp.assign(n+1,vector<ll> (10,-1));
    for(ll i =0;i<v.size();++i){
        string tmp = v[i];
        for(ll j = 0;j<p.size();++j){
            string dk = p[j];
            ll f = 1;
            for(ll k = 0;k<tmp.size();++k){
                ll ele =  tmp[k]-'0';
                ll ele2 =  dk[k]-'0';
                if(ele == 1){if(ele2 == 0){f = 0;break;}}
            }

            if(f & 1){
                ll op = 0;
                for(ll k = 0;k<tmp.size();++k){
                    ll ele =  tmp[k]-'0';
                    ll ele2 =  dk[k]-'0';
                    if(ele == 0 and ele2 == 1){
                        ++op;
                    }
                }
                dp[i][j] = op;
            }
        }
    }

    for(ll i = 0;i<n+1;++i){
        forj(2050){
            for(ll k = 0;k<10;++k){
                dk[i][j][k] = -1;
            }
        }
    }


    ll ok = dfs(0,0,0);
    cout<<n<<" "<<k<<endl;
    // cout<<ok<<endl;return;
    if(ok == 0){ans = "-1";}
    else{
        ans = "";
        cout<<"ok\n";
        findans(0,k,0);
        cout<<"ok\n";
        cout<<ans<<endl;
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}*/