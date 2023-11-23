#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    ll a[n];
    ll b[n];

    map<ll,ll> mp;
    vector<ll> ones;
    vector<ll> zeroes;

    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
        b[i] = a[i];
        mp[a[i]] = i;//store the position
    }

    string s;
    cin>>s;

    for(ll i=0;i<s.size();i++){
        if(s[i] == '0'){
            zeroes.push_back(a[i]);
        }
        else{
            ones.push_back(a[i]);
        }
    }

// Sorting everything in descending order using reverse
    sort(zeroes.begin(),zeroes.end());
    reverse(zeroes.begin(),zeroes.end());

    sort(ones.begin(),ones.end());
    reverse(ones.begin(),ones.end());

    sort(a,a+n);
    reverse(a,a+n);

    int i;
    // Add ones to there proper position
    for(i=0;i<ones.size();i++){
        b[mp[ones[i]]] = a[i];
    }
    
    // Add zeroes to there proper position
    for(ll j=0;j<zeroes.size();j++){
        b[mp[zeroes[j]]] = a[i];
        i++;
    }

    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}