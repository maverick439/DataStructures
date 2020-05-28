#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int arr[],int books,int stud, int curr_min){
    int studentUsed = 1;
    int pages_reading = 0;
    for(int i=0;i<books;i++){
        if(pages_reading + arr[i] > curr_min){
            studentUsed++;
            pages_reading = arr[i];
            if(studentUsed > stud){
                return false;
            }
        }
        else {
            pages_reading += arr[i];
        }
    }
    return true;

}

int findMinPages(int a[],int s,int e,int n,int stud){
    int ans = e;
    while(s <= e){
        int mid = (s+e)/2;
        if (isPossible(a,n,stud,mid)){
            ans = min(ans,mid);
            e = mid - 1;
        }
        else {
            s = mid+1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {10,20,30,40};
    int stud = 2;
    int n = 4;  
    int start = 40;
    int end = 100;
    int ans = findMinPages(arr,start,end,n,stud);
    cout<<ans;
}
