//Rotate a 2D matrix without using extra space by 90*

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
