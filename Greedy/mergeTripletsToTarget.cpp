/**
 * https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
 * 
 * Solution:
 * https://leetcode.com/problems/merge-triplets-to-form-target-triplet/discuss/1268649/Divide-triplets-in-2-classes-or-detailed-video-solution
 * */

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>res(3,0);
        for(int i=0; i< triplets.size(); i++){
            if(target[0] >= triplets[i][0] && target[1] >= triplets[i][1] && target[2] >= triplets[i][2]){
                res[0] = max(triplets[i][0], res[0]);
                res[1] = max(triplets[i][1], res[1]);
                res[2] = max(triplets[i][2], res[2]);
            }
        }
        return res == target;
    }
};

/*
Concept:
If triplet[i][0 or 1 or 2] > target[0 or 1 or 2] then it should be dicarded as it will never allow us to reach the result

*/