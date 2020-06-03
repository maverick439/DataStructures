//The following problem of chopsticks is from Codechef
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n; int d; int arr[100000];
	cin>>n>>d;
	for(int i=0;i<n;i++)
		cin>>arr[i];

	sort(arr,arr+n);
	int ans = 0;
	for(int i=0;i<n-1;i++){
		if(arr[i+1] - arr[i] <= d){
		    i++;
            ans++;
        }
	}
    cout<<ans;
}
