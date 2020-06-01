#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int minCoins(int *a,int n,int money){
    int res = 0;
    while(money>0){
        int index = upper_bound(a,a+n,money)-a;
        cout<<"Money"<<a[index-1]<<endl;
        money = money - a[index-1];
        res++;
    }
    return res;
}

int main() {
    int money; 
    cin >> money;
    int coins []= {1,2,5,10,20,50,100,200,500,1000};
    int n = sizeof(coins)/sizeof(int);
    int ans = minCoins(coins, n, money);
    cout<<"Coins -> "<<ans<<endl;
}

