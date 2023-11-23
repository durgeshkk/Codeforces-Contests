#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    string s;
    cin>>s;

    map<char,ll> mp;
    mp['a'] = 0;

    for(char i='a';i<='z';i++){
        mp[i] = i-96;
    }
/*
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }*/
    if(s[0] == 'a'){
        cout<<s[1]-'a'<<endl;
    }
    else if(s[0] == 'b'){
        if(s[1] > s[0]){
            cout<<26*1 + mp[s[1]] - 2<<endl;
        }
        else{
            cout<<26*1 + mp[s[1]]-1<<endl;
        }

    }
    else if(s[0] == 'c'){
        if(s[1] > s[0]){
            cout<<26*2 + mp[s[1]] - 3<<endl;
        }
        else{
            cout<<26*2 + mp[s[1]]-2<<endl;
        }
    }
    else if(s[0] == 'd'){
        if(s[1] > s[0]){
            cout<<26*3 + mp[s[1]] - 4<<endl;
        }
        else{
            cout<<26*3 + mp[s[1]]-3<<endl;
        }
    }
    else if(s[0] == 'e'){
        if(s[1] > s[0]){
            cout<<26*4 + mp[s[1]] - 5<<endl;
        }
        else{
            cout<<26*4 + mp[s[1]]-4<<endl;
        }
    }
    else if(s[0] == 'f'){
        if(s[1] > s[0]){
            cout<<26*5 + mp[s[1]] - 6<<endl;
        }
        else{
            cout<<26*5 + mp[s[1]]-5<<endl;
        }
    }
    else if(s[0] == 'g'){
        if(s[1] > s[0]){
            cout<<26*6 + mp[s[1]] - 7<<endl;
        }
        else{
            cout<<26*6 + mp[s[1]]-6<<endl;
        }
    }
    else if(s[0] == 'h'){
        if(s[1] > s[0]){
            cout<<26*7 + mp[s[1]] - 8<<endl;
        }
        else{
            cout<<26*7 + mp[s[1]]-7<<endl;
        }
    }
    else if(s[0] == 'i'){
        if(s[1] > s[0]){
            cout<<26*8 + mp[s[1]] - 9<<endl;
        }
        else{
            cout<<26*8 + mp[s[1]]-8<<endl;
        }
    }
    else if(s[0] == 'j'){
        if(s[1] > s[0]){
            cout<<26*9 + mp[s[1]] - 10<<endl;
        }
        else{
            cout<<26*9 + mp[s[1]]-9<<endl;
        }
    }
    else if(s[0] == 'k'){
        if(s[1] > s[0]){
            cout<<26*10 + mp[s[1]] -11<<endl;
        }
        else{
            cout<<26*10 + mp[s[1]]-10<<endl;
        }
    }
    else if(s[0] == 'l'){
        if(s[1] > s[0]){
            cout<<26*11 + mp[s[1]] - 12<<endl;
        }
        else{
            cout<<26*11 + mp[s[1]]-11<<endl;
        }
    }
    else if(s[0] == 'm'){
        if(s[1] > s[0]){
            cout<<26*12 + mp[s[1]] - 13<<endl;
        }
        else{
            cout<<26*12 + mp[s[1]]-12<<endl;
        }
    }
    else if(s[0] == 'n'){
        if(s[1] > s[0]){
            cout<<26*13 + mp[s[1]] - 14<<endl;
        }
        else{
            cout<<26*13 + mp[s[1]]-13<<endl;
        }
    }
    else if(s[0] == 'o'){
        if(s[1] > s[0]){
            cout<<26*14 + mp[s[1]] - 15<<endl;
        }
        else{
            cout<<26*14 + mp[s[1]]-14<<endl;
        }
    }
    else if(s[0] == 'p'){
        if(s[1] > s[0]){
            cout<<26*15 + mp[s[1]] - 16<<endl;
        }
        else{
            cout<<26*15 + mp[s[1]]-15<<endl;
        }
    }
    else if(s[0] == 'q'){
        if(s[1] > s[0]){
            cout<<26*16 + mp[s[1]] - 17<<endl;
        }
        else{
            cout<<26*16 + mp[s[1]]-16<<endl;
        }
    }
    else if(s[0] == 'r'){
        if(s[1] > s[0]){
            cout<<26*17 + mp[s[1]] - 18<<endl;
        }
        else{
            cout<<26*17 + mp[s[1]]-17<<endl;
        }
    }
    else if(s[0] == 's'){
        if(s[1] > s[0]){
            cout<<26*18 + mp[s[1]] - 19<<endl;
        }
        else{
            cout<<26*18 + mp[s[1]]-18<<endl;
        }
    }
    else if(s[0] == 't'){
        if(s[1] > s[0]){
            cout<<26*19 + mp[s[1]] - 20<<endl;
        }
        else{
            cout<<26*19 + mp[s[1]]-19<<endl;
        }
    }
    else if(s[0] == 'u'){
        if(s[1] > s[0]){
            cout<<26*20 + mp[s[1]] - 21<<endl;
        }
        else{
            cout<<26*20 + mp[s[1]]-20<<endl;
        }
    }
    else if(s[0] == 'v'){
        if(s[1] > s[0]){
            cout<<26*21 + mp[s[1]] - 22<<endl;
        }
        else{
            cout<<26*21 + mp[s[1]]-21<<endl;
        }
    }
    else if(s[0] == 'w'){
        if(s[1] > s[0]){
            cout<<26*22 + mp[s[1]] - 23<<endl;
        }
        else{
            cout<<26*22 + mp[s[1]]-22<<endl;
        }
    }
    else if(s[0] == 'x'){
        if(s[1] > s[0]){
            cout<<26*23 + mp[s[1]] - 24<<endl;
        }
        else{
            cout<<26*23 + mp[s[1]]-23<<endl;
        }
    }
    else if(s[0] == 'y'){
        if(s[1] > s[0]){
            cout<<26*24 + mp[s[1]] - 25<<endl;
        }
        else{
            cout<<26*24 + mp[s[1]]-24<<endl;
        }
    }
    else if(s[0] == 'z'){
        if(s[1] > s[0]){
            cout<<26*25 + mp[s[1]] - 26<<endl;
        }
        else{
            cout<<26*25 + mp[s[1]]-25<<endl;
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}