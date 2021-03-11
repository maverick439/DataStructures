//Approach 1: O(n*d)solution

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

//Approach 2: O(n) solution 
vector<int> rotLeft(vector<int> a, int d) {
    vector<int> result;
    for(int i=d;i<a.size();i++){
        result.push_back(a[i]);
    }
    for(int i=0;i<d;i++){
        result.push_back(a[i]);
    }
    return result;
}
