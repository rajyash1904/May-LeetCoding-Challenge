/*

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        vector<int> arr(n,-1);
        arr[0]= (nums[0]==0)? -1:1 ;
        
        for(int i=1;i<n;i++)
        {
            arr[i] = arr[i-1] + ((nums[i]==0)? -1 : 1) ;
        }
        
        int sol=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0) sol = i+1;
            else
            {
                if(mp.find(arr[i])==mp.end())
                {
                    mp[arr[i]]=i;
                }
                else
                {
                    sol=max(sol,i-mp[arr[i]]);
                }
            }
        }
        return sol;
    }
};
