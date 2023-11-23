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


void tree(ll v1,ll v2, vector<vector<ll>> &adjl,bool flag){
    adjl[v1].push_back(v2);
    adjl[v2].push_back(v1);

    if(adjl[v1].size() > 2 || (adjl[v2].size() > 2)){
        flag = true;
    }
}

void solve()
{
 
    ll n;
    cin>>n;

    vector<vector<ll>> adjl(n);
    vector<pair<ll,ll>> v;
    bool flag = false;
    
    for(ll i=0;i<n-1;i++){
        ll v1,v2;
        cin>>v1>>v2;
        v1--,v2--;

        ll a = min(v1,v2);
        ll b = max(v1,v2);

        v.push_back({a,b});

        adjl[a].push_back(b);
        adjl[b].push_back(a);

        if(adjl[a].size() > 2 || (adjl[b].size() > 2)){
            flag = true;
        }
        // tree(v1,v2,adjl,flag);
    }

/*
    for(ll i = 0;i<adjl.size();++i){
        cout<<"i : "<<i<<" | ";
        for(ll j = 0;j<adjl[i].size();++j){
            cout<<adjl[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
*/
    
    if(flag == true){
        cout<< -1 <<endl;
        return;
    }

    map<pair<ll,ll>,ll> ans;//O/p to be in fixed sequence
    ll start;

    for(ll i = 0;i<n;++i){
// starting with size 1 as bichme se agar start kiya 
// toh its difficult to maintain..
        if(adjl[i].size() == 1){
            start = i;
            break;
        }
    }

    bool vis[n] = {false};
    vis[start] = true;

    ll a = 3;// wt wil be 3-2-3-2- ..
    while(1){
        ll ini = start;

        for(ll k = 0;k<adjl[start].size();++k){
            if(!vis[adjl[start][k]]){
                
                vis[adjl[start][k]] = true;
                start = adjl[start][k];
                break;
            }
        }

        if(ini == start){
            break;
        }

        ans[{min(ini,start),max(ini,start)}] = a;

        if(a == 3){
            a = 2;
        }
        else{
            a = 3;
        }
    }

    for(ll i = 0;i<v.size();++i){
        cout<< ans[{v[i].first,v[i].second}]<<" ";
    }
    cout<<endl;
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