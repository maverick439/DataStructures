//To find the no of 1s in the binary expression
//To find the set bits 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    for( ;n > 0; n = n>>1)
        ans = ans + (n&1);
    cout<<ans;

}

//Alternate method //Better solution
/*
int main() {
    int n;
    cin>>n;
    int count = 0;
    while(n>0){
        n = n & (n-1);
        count++;
    }
    cout<<count;
    return 0;
}*/
