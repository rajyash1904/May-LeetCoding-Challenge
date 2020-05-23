/*

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:

https://assets.leetcode.com/uploads/2019/01/30/interval1.png

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 

Note:

1. 0 <= A.length < 1000
2. 0 <= B.length < 1000
3. 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

static const auto speedup = []() { 
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); 
    std::cout.tie(NULL);
    return 0; 
}();

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> sol;
        int i=0;
        int j=0;
        while(i<A.size() && j<B.size()){
            if(A[i][0]>B[j][1]) j++;
            else if(A[i][1]<B[j][0]) i++;
            else{
                sol.push_back({max(A[i][0],B[j][0]),min(A[i][1],B[j][1])});
                if(A[i][1]<B[j][1]) i++;
                else if(A[i][1]>B[j][1]) j++;
                else {
                    i++;
                    j++;
                }
            }
        }
        return sol;
    }
};
