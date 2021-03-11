//Approach 1

vector<int> rotLeft(vector<int> a, int d) {
    int n = a.size();
    while(d--){
        int temp = a[0];
        for(int i=0;i<a.size();i++){
            a[i] = a[i+1];
        }
        a[n-1] = temp;
    }
    return a;

}
