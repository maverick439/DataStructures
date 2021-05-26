//Rotate a 2D matrix without using extra space by 90*

// ----------------------L E E T -----------C O D E-------------------

/**
Concept
1. Matrix Transpose
2. Reverse Columns
**/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){ return; }
        matrixTranspose(matrix);
        columnReverse(matrix);
    }
private:
    void matrixTranspose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i < n;i++){
            for(int j=i; j < n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void columnReverse(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i < n;i++){
            for(int j=0;j < n/2;j++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
    }
};

/**
Initially
[1,2,3]
[4,5,6]
[7,8,9]

After Transpose
[1,4,7]
[2,5,6]
[3,6,9]

After Column Reverse
[7,4,1]
[6,5,2]
[9,6,3]

**/




#include <iostream>
using namespace std;
const int n = 3;
void transpose(int arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}
void colReverse(int arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0,k=n-1; j < k ;j++,k--){
            swap(arr[j][i],arr[k][i]);
        }
    }
}
void printMatrix(int arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    transpose(arr);
    printMatrix(arr);
    cout<<endl;
    colReverse(arr);
    printMatrix(arr);
}

