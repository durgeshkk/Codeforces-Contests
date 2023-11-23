#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define endl '\n'

const ll mod = 1e9 + 7;
const ll INF = 1e18 + 2;
const ll _INF = -1e18;

#define sz(x) (ll)(x).size()
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()


void solve(){
    ll n , m;
    cin >> n >> m;

    vector<ll> a(n) , b(n);

    a[0] = INF;
    for(int i=1; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    sort(all(a)), sort(all(b));

    ll idx1 = 0 , idx2 = 0;

    ll ans = 0;

    ll last = -1;

    while(69){
        if(idx2 == n) break;

        if(a[idx1] < b[idx2]){
            idx1++;
            idx2++;
        }
        else{
            ans++;
            last = b[idx2];
            idx2++;

        }
    }
    cout<<ans<<" "<<last<<endl;

    if(last > m){
        cout << m * (ans - 1 ) << endl;
    }
    else{
        cout << (last - 1) * (ans - 1) + (m - last + 1) * ans << endl;
    }

    

}


int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    
    ll tt = 1;
    cin>>tt;
    while(tt--){
       solve();
    }
    return 0;
}