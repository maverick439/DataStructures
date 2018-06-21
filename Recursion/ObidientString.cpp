/*
Take as input str, a string.
Write a recursive function that checks if the string was generated 
using the following rules and returns a Boolean value: 
a. the string begins with an 'a' 
b. each 'a' is followed by nothing or an 'a' or "bb" 
c. each "bb" is followed by nothing or an 'a' 
Print the value returned.
*/

#include <iostream>
#include <cstring>
using namespace std;

bool obidientstring(string s,int i,int n){
	if(i==n-1)
		return true;
	if(s[i] == 'a'){
		if(s[i+1]=='a')
			return obidientstring(s,i+1,n);
		if(s[i+1]=='b')
			return obidientstring(s,i+1,n);
		else if(s[i+1]=='\0')
			return true;
	}
	if(s[i]=='b'){
		if(s[i+1]=='b' && s[i+2]=='a')
			return obidientstring(s,i+2,n);
		if(s[i+1]=='b' && s[i+2]=='\0')
			return false;
	}
	return false;
}
int main(){
	string s;
	cin>>s;
	int len = sizeof(s);
	bool ans = obidientstring(s,0,len);
	if(ans == true)	cout<<"true";
	else	cout<<"false";
}
