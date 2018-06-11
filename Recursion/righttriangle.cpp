/*Take as input N, a number. Print the following pattern (for N =4)

    *
    * *
    * * *
    * * * *
*/

#include <iostream>
using namespace std;

void star(int n,int i){
	int k = i;
	if(n==1){
		cout<<"* ";
		cout<<endl;
	}
	else if(k <= n){
		for(int j=1;j<=k;j++){
			cout<<"* ";
		}
		cout<<"\n";
		star(n,i+1);
	}
}
int main(){
	int n;
	cin>>n;
	star(n,1);
}
