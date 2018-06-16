/* Input - abc(x)
Output - x
*/
#include <iostream>
#include <string.h>
using namespace std;

void bracket(string str,int n,int i){
	int k=0;
	if(str[i] == '\0')
		return;
	if(str[i] == '('){
		i++;
		while(str[i] != ')'){
			cout<<str[i];
			i++;	
		}
		cout<<" ";
	}
	return bracket(str,n,i+1);
}
int main(){
	string str;
	cin>>str;
	bracket(str,str.size(),0);
	return 0;
}
