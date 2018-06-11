/*Take as input N, a number. Print the following pattern (for N = 5)

       *    *   *   *   *   
       *    *   *   *
       *    *   *
       *    *   
       *    

*/
#include <iostream>
using namespace std;

void star(int n){
	if(n==1){
		cout<<"* ";
		cout<<endl;
	}
	else if(n>1){
		for(int i=1;i<=n;i++){
			cout<<"* ";
		}
		cout<<"\n";
		star(n-1);
	}
}
int main(){
	int n;
	cin>>n;
	star(n);
}
