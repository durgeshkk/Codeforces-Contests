#include <bits/stdc++.h>

#define int long int
#define endl '\n'
typedef long long ll;

using namespace std;

void solve()
{
    int n,v;
    cin>>n>>v;
    int a[n],b[n],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    double mn=1e9;
    for(int i=0;i<n;i++)
    {
        mn=min(mn,b[i]*1.0/a[i]);
    }
    cout<<fixed<<setprecision(10)<<min(mn*sum,v*1.0);

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc=1;
//    cin>>tc;
    while(tc--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
