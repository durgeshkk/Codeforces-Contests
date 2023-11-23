// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int solve(int N, int A[])
    {
        int i=0,j=1;
        
        vector<int> v(N);

        // cout<<"HI\n";
        while((i != j) && (j<N))
        {
            if((A[j]-A[i]) > 0)
            {
                v.push_back((A[j]-A[i]));
                i++;
                j = i+1;
            }
            else if(j == (N-1))
            {
                i++;
                j = i+1;
            }
            else
            {
                j++;
            }
        }
        // cout<<"HI\n";

        vector<int> sorted(N);

        for(int i=0;i<v.size();i++){
            sorted[i] = v[i];
        }

        for(int i=0;i<v.size();i++){
            cout<<sorted[i]<<" ";
        }
        cout<<endl;

        sort(sorted.begin(),sorted.end());

        // cout<<"HI\n";
        for(int i=0;i<v.size();i++){
            // cout<<i<<"HI\n";
            if(sorted[i] == v[i]){

            }
            else{
                return 0;
            }
        }
        // cout<<"HI\n";
        return 1;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];

        for (int i = 0; i < N; i++) cin >> A[i];
       

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}
  // } Driver Code Ends