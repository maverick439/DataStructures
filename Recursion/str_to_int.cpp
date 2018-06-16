/* INput a string 1234 and output it as an integer
using recursion.
Output - 1234
*/
#include <iostream>
#include <string.h>
using namespace std;
int num;
void toint(string str,int n,int i){
	if(str[i] == '\0'){
		cout<<num;
		return;
	}
	else{
		int x = str[i] - 48;
//		cout<<x<<;
		num = num*10 + x ;
		toint(str,n,i+1);
	}
}
int main(){
	string str;
	cin>>str;
	toint(str,str.size(),0);
}
