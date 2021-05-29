/**
 * HOT *****
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 * 
 * 
 * 
 * You can watch this amazing video for understanding.
 * Link - https://www.youtube.com/watch?v=LPFhl65R7ww
 * 
 * */

// Approach  - O(log(m+n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();  int y = nums2.size();
        if(x > y){ 
            nums1.swap(nums2);
            swap(x,y);
            //return findMedianSortedArrays(nums2, nums1); 
        }
        int low = 0; int high = x; double ans = 0;
        
        while(low <= high){
            int partitionX = (low + high)/2;
            int partitionY = (x+y+1)/2 - partitionX;    
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            // Found the correct partition
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                // Calculate average of two medians
                if((x+y)%2 == 0){
                    ans = (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2.0;
                }
                // Single median case
                else{
                    ans = (double)max(maxLeftX, maxLeftY);
                }
                return ans;
            }
            // We are too far on the right in partition
            else if(maxLeftX > minRightY){
                high = partitionX - 1;
            }
            // We are too far on the left in partition
            else{
                low = partitionX + 1;
            }
        }
        return 1.0;
    }
};

//Approach O(N*N)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    for(int i=0;i < nums2.size();i++){ nums1.push_back(nums2[i]); }
    int n = nums1.size();
    sort(nums1.begin(),nums1.end());
    double median = 0;
    if(n%2 == 0){ median = (nums1[n/2 -1] + nums1[n/2])/(double)2; }
    else{ median = nums1[(n+1)/2 -1]; }
    return median;
}