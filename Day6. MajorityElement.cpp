/*

Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

//Greedy Algorithm PROBLEM

/*Solution Approach :  
           If we cancel out each occurrence of an element e with all the other elements that are different
           from e then e will exist till end if it is a majority element. Loop through each element and maintains
           a count of the element that has the potential of being the majority element. If next element is same 
           then increments the count, otherwise decrements the count. If the count reaches 0 then update the potential
           index to the current element and reset count to 1.
           */
   
 
 class Solution {
public:
    Solution() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}    //Fast IO
    int majorityElement(vector<int>& nums) {
        int majorityIndex = 0;
            for (int count = 1, i = 1; i < nums.size(); i++) {
                nums[majorityIndex] == nums[i] ? count++ : count--;
                if (count == 0) {
                    majorityIndex = i;
                    count = 1;
                }
            }

            return nums[majorityIndex];
        
    }
};
