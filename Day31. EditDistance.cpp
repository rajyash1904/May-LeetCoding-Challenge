/*

Edit Distance

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

class Solution {
public:
    int minDistance(string w1, string w2) 
    {
        int m=w1.size();
        int n=w2.size();
        int dp[m+1][n+1];
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else if(w1[i-1]==w2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j] = 1 +min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) ;
            }
        }
        
        return dp[m][n];
    }
};
