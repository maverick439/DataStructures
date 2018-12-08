#include <iostream>
using namespace std;

int solveGrid(int mat[][100],int m,int n){
	int dp[100][100] = {};

	//Setting Base case
	dp[0][0] = mat[0][0];
	//fill first row
	for(int c=1;c<n;c++)	dp[0][c] = dp[0][c-1] + mat[0][c];
	//fill first column
	for(int r=1;r<m;r++)	dp[r][0] = dp[0][r-1] + mat[r][0];
	//For 1st row onwards
	for(int r=1;r<m;r++){
		for(int c=1;c<n;c++){
			dp[r][c] = min(dp[r][c-1],dp[r-1][c]) + mat[r][c];
		}
	}
	return dp[m-1][n-1];
}


int main(){
	int m,n;
	cin>>m>>n;
	int arr[100][100];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	int res = solveGrid(arr,m,n);
	cout<<res;
	
}
/*
//Input
3 3
1 2 3
4 8 2
5 3 3
//Output  = 11
Since 1->2->3->2->3
*/
