#include<bits/stdc++.h>
using namespace std;

int bracket_seq(string str){
    stack<char> s;
    int count=0;

    int i=0;
    s.push(str[0]);
    char prev = ')';
    while((i<str.size())){
        if(str[i] == '(' && str[i+1] == '('){//palindrome
            count++;            
        }
        else if(str[i] == '(' && str[i+1] == ')'){//regular
            count++;
        }
        else{//brace start from ')' so now only palindrome is pssbl
            prev = ')';
        }
        i++;
    }
}

int main()
{
    string s;
    cin>>s;
    return 0;
}