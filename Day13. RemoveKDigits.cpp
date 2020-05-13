/*

Remove K Digits

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
1. The length of num is less than 10002 and will be ≥ k.
2. The given num does not contain any leading zero.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

//Time: O(KN)   space: O(1)

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n==k) return "0";
        for(int j=0;j<k;j++){
            int i=0;
            while(i<num.size()-1 && num[i]<=num[i+1]){
                i++;
            }
            num.erase(i,1);
        }
        while(num.size()>1 && num[0]=='0'){
            num.erase(0,1);
        }
        if(num.size()==0) return "0";
        return num;
    }
};
