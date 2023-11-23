// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
  
// A utility function to get minimum of two numbers 
int minVal(int x, int y) { return (x < y)? x: y; } 
  
// A utility function to get the 
// middle index from corner indexes. 
int getMid(int s, int e) { return s + (e -s)/2; } 
  
/* A recursive function to get the
minimum value in a given range 
of array indexes. The following 
are parameters for this function. 
  
    st --> Pointer to segment tree 
    index --> Index of current node in the 
          segment tree. Initially 0 is 
          passed as root is always at index 0 
    ss & se --> Starting and ending indexes 
                of the segment represented 
                by current node, i.e., st[index] 
    qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index) 
{ 
    // If segment of this node is a part 
    // of given range, then return 
    // the min of the segment 
    if (qs <= ss && qe >= se) 
        return st[index]; 
  
    // If segment of this node
    // is outside the given range 
    if (se < qs || ss > qe) 
        return INT_MAX; 
  
    // If a part of this segment
    // overlaps with the given range 
    int mid = getMid(ss, se); 
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1), 
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2)); 
} 
  
// Return minimum of elements in range
// from index qs (query start) to 
// qe (query end). It mainly uses RMQUtil() 
int RMQ(int *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        cout<<"Invalid Input"; 
        return -1; 
    } 
  
    return RMQUtil(st, 0, n-1, qs, qe, 0); 
} 
  
// A recursive function that constructs
// Segment Tree for array[ss..se]. 
// si is index of current node in segment tree st 
int constructSTUtil(vector<ll> arr, int ss, int se,
                                int *st, int si) 
{ 
    // If there is one element in array,
    // store it in current node of 
    // segment tree and return 
    if (ss == se) 
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
  
    // If there are more than one elements, 
    // then recur for left and right subtrees 
    // and store the minimum of two values in this node 
    int mid = getMid(ss, se); 
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1), 
                    constructSTUtil(arr, mid+1, se, st, si*2+2)); 
    return st[si]; 
} 
  
/* Function to construct segment tree 
from given array. This function allocates
memory for segment tree and calls constructSTUtil() to 
fill the allocated memory */
int *constructST(vector<ll> arr, int n) 
{ 
    // Allocate memory for segment tree 
  
    //Height of segment tree 
    int x = (int)(ceil(log2(n))); 
  
    // Maximum size of segment tree 
    int max_size = 2*(int)pow(2, x) - 1; 
  
    int *st = new int[max_size]; 
  
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n-1, st, 0); 
  
    // Return the constructed segment tree 
    return st; 
} 
  



void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>v1(n),v2(n);
    vector<pair<ll,ll>>vp;
    for(ll i=0;i<n;i++){
        cin>>v1[i];
    }

    for(ll i=0;i<n;i++){
        cin>>v2[i];
        vp.push_back({v1[i],v2[i]});
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(vp.begin(),vp.end());
    
    vector<ll>r;
    for(ll j=0;j<n;j++){
       r.push_back(vp[j].second);     
    }
    
    int *st = constructST(r, n); 
    ll t=0;
    ll tot=k;
    ll mx=*max_element(v1.begin(),v1.end());

    while(k>0 && tot<mx){
       ll r = upper_bound(v1.begin(),v1.end(),tot)-v1.begin(); 
       ll mn=RMQ(st,n,r,n-1);
       if(k < mn){
           break;
       }
       k-=mn;
       tot+=k;     
    }
    
    if(tot<mx){
        cout<<"NO"<<endl;
    }    
    else{
        cout<<"YES"<<endl;
    }
}
