#include <iostream>
using namespace std;

float squareroot(int n,int p){
    if(n<=0)
        return 0;
    int l = 1;
    int r = n;
    float ans = -1;
    while(l<=r){
        int mid = (l + r)/2;
        if(mid*mid == n){
            ans = mid;
            break;
        }
        if(mid*mid > n){
            r = mid-1;
        }
        else{
            ans = mid;
            l = mid+1;
        }
    }

    //Fractional Part as per precision
    float inc  = 0.1;
    for(int i=0;i<p;i++){
        while(ans*ans <= n){
            ans = ans + inc;
        }
        ans = ans - inc;
        inc = inc/10;
    }

    return ans;
}

int main() {
    int n,p;
    cin>>n>>p;
    float ans = squareroot(n,p);
    cout<<ans;

}
