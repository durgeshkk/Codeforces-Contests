// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya h....

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {

        ll n, k;
        cin >> n >> k;
        ll arr[n+1];

        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        if(arr[1]!=1){
            cout<<"1"<<endl;
            continue;
        }
        ll l=1,r=1e15;
        ll ans=-1;

        l = 0,r = 20;
        while(r>=l){
            ll mid=(l+r)/2;
            ll tm=mid;
            ll cnt=0;
            cout<<mid<<" : ";
            for(ll i=n;i>=1;i--){

                if(arr[i]>tm){
                    continue;
                }

                ll diff=(tm-arr[i]+i)/i;
                tm-=(diff*i);
                cnt+=diff;
                cout<<diff<<" "<<tm<<" "<<cnt<<endl;
            }

            if(cnt<=k){
                l=mid+1;
            }else{
                r=mid-1;
                ans=mid;

            }
        }
        cout<<ans<<endl;
    }

    return 0;
}