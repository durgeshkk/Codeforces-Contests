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

int vis[200005];
int mx = INT16_MIN;

void dfs(vector<int> &v,int idx,int sum){
    if(idx > v.size()-1){
        return;
    }

    sum += v[idx];

    if(vis[idx] == -1){
    }
    else{
        return;
    }

    if(sum > mx){
        mx = sum;
        vis[idx] = mx;
    }

    idx += v[idx];
    dfs(v,idx,sum);
}

void solve()
{
 
    int n;
    cin>>n;
    mx = INT16_MIN;
    for(int i = 0;i<200005;i++){
        vis[i] = -1;
    }
    
    vector<int> v(n,0);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
/*
    vector<ll> ans(n);
    ll i = 0;
    ll s = v[i].first + v[i].second;
    
    for(ll j = i+1;j<v.size();j++){

        if(i == v.size()){
            break;
        }

        if(s > n && (i!=v.size())){
            ll s = v[i+1].first + v[i+1].second;
            ans[i] = (s);
            i++;
            j = i+1;
        }
        else{
            if(s == v[j].second){
                s += v[i].first;
            }
        }

    }

    for(ll i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;*/

/* TLE TC 3:
    vector<ll> v2;
    for(ll i=0;i<n;i++){
        v2.push_back(v[i] + (i+1));
    }

    ll i = 0;
    ll t=0;
    vector<ll> ans;

    while(t <= n){
        if(i == v.size()){
            break;
        }

        t = v2[i];
        if(t>n){
            ans.push_back(v2[i]);
            i++;
            t=0;
            continue;
        }
        v2[i] += v[t-1];
        if(v2[i]>n){
            ans.push_back(v2[i]);
            i++;
            t=0;
        }

    }

    for(ll i = 0;i<ans.size();i++){
        ans[i] -= (i+1);
    }

    for(ll i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    sort(ans.begin(),ans.end());
    cout<<ans[ans.size()-1]<<endl;*/
    
    

    for(int i =0;i<n;i++){
        dfs(v,i,0);
    }

    cout<<mx<<endl;
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