//https://www.hackerrank.com/challenges/angry-children/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms

#include <bits/stdc++.h>
using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int i=0,j=k-1;
    int diff=INT_MAX;
    while(j < n){
        int x = arr[j] - arr[i];
        if(x < diff)
            diff = x;
        i++;
        j++;
    }
    return diff;

}
