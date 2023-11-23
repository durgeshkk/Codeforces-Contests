#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        long long int sum = 0;
        vector<int> a(n);
        for(int i=0; i<n; i++) 
        {
            cin>>a[i];
            sum += abs(a[i]);
        }
        bool flag = false;
        long long int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i] < 0)
            {
                if(!flag)
                {
                    ans++;
                    flag = true;
                }
            }
            else if(a[i] == 0) continue;
            else{
                flag = false;
            }
        }

        cout<<sum<<" "<<ans<<endl;
    }
}