/* Generate prime numbers from start to end
2
1 10
3 5

Sample Output:
2 3 5 7
3 5
*/

#include <iostream>
#include <cstring>
using namespace std;

 void sieveofEratosthenes(int start,int end){
 	bool prime[end-start+1];
 	memset(prime,true,sizeof(prime));

 	for(int p=2;p*p < end;p++){
 		if(prime[p] == true){
 			for(int i = p*2;i<=end;i = i+p)
 				prime[i] = false;
 		}
 	}
 	for(int p=start;p<=end;p++)
 		if(prime[p])
 			cout<<p<<" ";
 }
int main(){
	int n,i;
	int start,end;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>start;
		cin>>end;
		sieveofEratosthenes(start,end);
	}
}
