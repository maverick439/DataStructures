/**
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
 * 
 * https://leetcode.com/problems/4sum/
 * */


/*
Constraints:
1. Sum of 4 index values = target
2. All indexes should be unique
3. No duplicate Quad

Use SET -> for Unique quadruplets
Approach 1: Brute Force O(N*N*N*N LogN)
4 Loops + SET for unique ordering
sum = n[i] + n[j] + n[k] + n[l]
*/

/*
Sort Initially
Approach 2: Brute Force O(N*N*N LogN)
Use Two pointer technique + SET for unique ordering 
3 Loops
start = j+1;  end = n-1;
sum = n[i] + n[j] + n[start] + n[end]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> result;
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int start = j+1; int end = n-1;
                while(start < end){
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if(sum > target){ end--; }
                    else if(sum < target){
                           start++;
                    }
                    else{
                        vector<int>t { nums[i], nums[j], nums[start], nums[end] };
                        result.insert(t);
                        start++; end--;
                    }
                }
            }
        }
        for(auto it: result){
            ans.push_back(it);
        }
        return ans;
    }
};

/*
Approach 3: 
n[k] + n[l] = target - (n[i] + n[j])
i < j < k < l
Use Unordered Map - Store all possible Two Sums in Hash
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int, int>>m;
        int n = nums.size();
        if(n < 4){ return ans; }
        sort(nums.begin(), nums.end());
        
        // Prepare the Unordered map with the half sum
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int sum = nums[i]+nums[j];
                m[sum].push_back(make_pair(i,j));
            }
        }
        
        for(int i=0; i<n-1; i++){
            if(i>0 && nums[i] == nums[i-1]){ continue; } // Avoid duplicates
            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j] == nums[j-1]){ continue; } // Avoid duplicates
                int sum = target - (nums[i]+nums[j]);
                if(m.find(sum) != m.end()){
                    for(auto it : m[sum]){
                        int k = it.first;
                        int l = it.second;
                        // To maintain increasing order
                        if(k>j){
                             if(!ans.empty() && ans.back()[0]==nums[i] and ans.back()[1]==nums[j] and ans.back()[2]==nums[k] and ans.back()[3]==nums[l]){
                                 continue;
                             }
                            vector<int>temp = {nums[i], nums[j], nums[k], nums[l]};
                            ans.push_back(temp);
                        }
                    }
                }
                
            }
        }
        return ans;
    }
};