//Naive Approach
int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    for(int i=0;i< nums.size();i++){
        int sum = 0;
        for(int j=i;j < nums.size();j++){
            sum += nums[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

//Approach 2
int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int currsum = 0;
    unordered_map<int,int> prevSum;

    for(int i=0;i<nums.size();i++){
        currsum += nums[i];
        if(currsum == k){
            count++;
        }

        if(prevSum.find(currsum - k) != prevSum.end()){
            count += prevSum[currsum-k];
        }
        prevSum[currsum]++;
    }
    return count;
}
