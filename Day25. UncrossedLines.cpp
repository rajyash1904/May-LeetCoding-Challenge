/*

We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:
https://assets.leetcode.com/uploads/2019/04/26/142.png

Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
 

Note:

1. 1 <= A.length <= 500
2. 1 <= B.length <= 500
3. 1 <= A[i], B[i] <= 2000

   Hide Hint #1  
Think dynamic programming. Given an oracle dp(i,j) that tells us how many lines 
A[i:], B[j:] [the sequence A[i], A[i+1], ... and B[j], B[j+1], ...] are uncrossed, can we write this as a recursion?

*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m=A.size();
        int n=B.size();
        vector<int> curr (n,0);
        vector<vector<int>>arr (m,curr);
        
        if(A[0]==B[0]) arr[0][0]=1;
        for(int i=1;i<m;i++)
        {
            if(A[i]==B[0]) arr[i][0]=1;
            else arr[i][0]=arr[i-1][0];
        }
        
        for(int i=1;i<n;i++)
        {
            if(B[i]==A[0]) arr[0][i]=1;
            else arr[0][i]=arr[0][i-1];
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(A[i]==B[j])
                {
                    arr[i][j]=arr[i-1][j-1] + 1;
                }
                else
                {
                    arr[i][j]=max(arr[i-1][j],max(arr[i-1][j-1],arr[i][j-1]));
                }
            }
        }
        return arr[m-1][n-1];
    }
};
