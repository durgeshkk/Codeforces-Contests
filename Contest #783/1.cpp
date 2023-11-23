// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int solve(int N, string S) {
        // code here
        int ans=0;
        set<char> s;
        int i=0;
            // char req = S[0]; 
        while(i < N){
            s.insert(S[i]);
            i++;
        }
        ans = s.size()-1;
        return ans;
    }
};


// { Driver Code Starts.
//Position this line where user code will be pasted.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string S;
        cin>>S;
        Solution ob;
        cout << ob.solve(N, S) << "\n";
    }
    return 0;
}
  // } Driver Code Ends