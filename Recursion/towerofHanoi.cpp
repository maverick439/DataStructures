#include <iostream>
#include <math.h>
using namespace std;

int towerofHanoi(int n,char source,char dest,char helper){
	if(n==0) return 0;
	towerofHanoi(n-1,source,helper,dest);
	cout<<"Move "<<n<<"th disc from T"<<source<<" to T"<<dest<<endl;
	towerofHanoi(n-1,helper,dest,source);
}

int main(){
	int n,ans;
	cin>>n;
	towerofHanoi(n,'T1','T2','T3');
	int k = pow(2,n) - 1;
	cout<<k;
	return 0;
}
