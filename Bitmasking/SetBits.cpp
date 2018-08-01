//To find the no of 1s in the binary expression

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
