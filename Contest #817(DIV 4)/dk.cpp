#include<bits/stdc++.h> 
using namespace std;

int mod=pow(10 , 9) + 7;
 
typedef long long ll;
typedef long double ld;


bool solve() {
    ll n, k;
    cin >> n;
    
    string s, s1 = "Timur";
    cin >> s;
    
    if(n!=5) return 0;
    
    sort(s.begin(),s.end());
    sort(s1.begin(),s1.end());
    
    
    return (s==s1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    //t = 1;
    while(t--){
        
       if (solve()) cout << "YES";
       else cout << "NO";
       
       cout << '\n';
    }  
    
        
    return 0;
}