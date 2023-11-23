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
void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> one(n),second(n);
    for(ll i=0;i<n;i++){
       cin>>one[i];
    }
    sort(one.begin(),one.end());
    reverse(one.begin(),one.end());
    ll sm1 = accumulate(one.begin(),one.end(),0);

    for(ll i=0;i<n;i++){
       cin>>second[i];
    }
    sort(second.begin(),second.end());
    reverse(second.begin(),second.end());
    ll sm2 = accumulate(second.begin(),second.end(),0);

/*
    if(sm1 >= sm2){
        cout<<0<<endl;
        return;
    }

    if(n == 1){
        cout<<1<<endl;
        return;
    }

    ll select = (n - (n/4));
    vector<ll> fo(select),fs(select);

    ll arr[n - select];

    sm1 = 0,sm2=0;
    for(ll i = 0;i<select;i++){
        fo[i] = one[i];
        fs[i] = second[i];

        sm1 += fo[i];
        sm2 += fs[i];
    }

    ll j = 0;
    for(ll i = select;i<n;i++,j++){
        arr[j] = second[i];
    }

    if(sm1 >= sm2){
        cout<<1<<endl;
        return;
    }

    j = (select);
    ll cnt = 0,f=0;
    ll ft = n;
    for(ll i = 0;i<ft;i++){

        if(sm1 >= sm2){
            cout<<cnt<<endl;
            return;
        }

        fo.push_back(100);
        if(j < n){
            fs.push_back(arr[j]);
            j++;
            sm2 += arr[j];
        }
        else{
            fs.push_back(0);
        }

        sm1 += 100;
        n++;
        select = (n - (n/4));
        cnt++;
    }
    cout<<cnt+1<<endl;*/

    for(ll i = 0;i<n;i++){
        if(i == 0){
            one[i] = one[i];
        }
        else{
            one[i] += one[i-1];
        }
    }

    for(ll i = 0;i<n;i++){
        if(i == 0){
            second[i] = second[i];
        }
        else{
            second[i] += second[i-1];
        }
    }

    ll x = n/4;
    x = (n-x);

    ll y = x;
    x--;//to check in vector since vector idx starts from 0 & 
    // x starts from 1
    y--;

    ll sm=0,sy=0;

    if(one[x] >= second[y]){
        cout<<0<<endl;
        return;
    }

    ll on  = n;
    while(sm+one[x]<second[y])
    {
        sm+=100;
        n++;
        if(n%4==0)
        {
            if(x!=0)
            x--;
            else
            {
                one[0]=0;
                x=0;
            }
        }
        else
        {
            if(y!=on-1)
            y++;
        }
        // cout<<"sm"<<sm<<"\n";
        // cout<<"a"<<a[x]<<"\n";
        // cout<<"b"<<b[y]<<"\n";
        // cout<<"x"<<x<<"\n";
        // cout<<"y"<<y<<"\n";
    }
    cout<<n-on<<"\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--)
   {
    //    cout<<"T : "<<t<<" ";
       solve();
    //    cout<<endl;
   }
   //solve();
   return 0;
}