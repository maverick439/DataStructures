/*
Recursion-Duplicate character formatting
Input - hello
Output - hel*lo
*/
#include <iostream>
#include <string.h>
using namespace std;

string duplicate(string s, int len, int i){
    if (s[i] == '\0')
        return s;
    if (s[i] == s[i - 1]){
        s.insert(i, "*");
        return duplicate(s, len + 1, i + 1);
    }
    else
        return duplicate(s, len, i + 1);
    return s;

}

int main(){
string s;
cin>>s;
//cout<<s.size();
string a = duplicate(s,s.size(),1);
cout<<a;
}
