/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false

*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<=1) return true;
        int l=0;
        int r=num/2;
        int mid;
       while(l<=r){
            mid=(r-l)/2 +l;
            if(num%mid==0 && mid==num/mid) return true;
            else if(mid>num/mid)  r=mid-1;
            else l=mid+1;
        }
        
        return false;
    }
};
