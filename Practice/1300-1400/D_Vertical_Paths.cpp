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

const int st=2e5 + 5;

vector<int> adjl[st+1];
vector<bool> vis(st+1);
vector<vector<int>> ans;
vector<int> vec(st+1);

void dfs(int vz,vector<int> &v){

    v.push_back(vz);

    if(adjl[vz].size() == 0){
        ans.push_back(v);
        v.clear();
        return;
    }

    vis[vz] = true;
    // cout<< vz << " ";

    for(auto it: adjl[vz]){
        if(!vis[it]){
            dfs(it,v);
        }
    }
}

void solve()
{
 
    int n;
    cin>>n;

    int root = -1;
    ans.clear();

    for(ll i=1;i<=n;++i){
        adjl[i].clear();
        vec[i] = 0;
        vis[i] = false;
    }

    for(ll i=0;i<n;++i){
        cin>>vec[i];
       if(vec[i] == (i+1)){
           root = vec[i];
           continue;
       }
       adjl[vec[i]].push_back(i+1);
    }

    vector<int> z;
    dfs(root,z);

    cout<<ans.size()<<endl;

    for(ll i = 0;i<ans.size();++i){
        cout<<ans[i].size()<<endl;

        for(ll j = 0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }
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