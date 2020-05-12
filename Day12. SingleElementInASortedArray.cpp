/*

Single Element In A Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.

*/

//One solution is linear traversing once xoring all elements  TIME: O(N) , SPACE: O(1)

/*An Efficient Solution can find the required element in O(Log n) time.
The idea is to use Binary Search. Below is an observation in input array.
All elements before the required have first occurrence at even index (0, 2, ..)
and next occurrence at odd index (1, 3, …). And all elements after the required
element have first occurrence at odd index and next occurrence at even index.*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int mid=(j-i)/2 + i;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1])  i=mid+2;
                else j=mid;
            }else{
                if(nums[mid]==nums[mid-1]) i=mid+1;
                else j=mid-1;
            }
        }
        return nums[i];
    }
};
