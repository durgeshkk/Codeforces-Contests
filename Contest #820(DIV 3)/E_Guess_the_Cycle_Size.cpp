#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
using namespace std;
 
int main(){
    ll x, y;
    for(ll i = 1;i<8;++i){
        for(ll j = i + 1;j<8;++j){
            cout << "? " << i << " " << j << endl;
            cin >> x;
            cout << "? " << j << " " << i << endl;
            cin >> y;
            if(x == -1) {
                cout << "! " << max(i, j) - 1 << endl;
                return 0;
            }

            if(x != y) {
                cout << "! " << x + y << endl;
                return 0;
            }
        }
    }
    
}
