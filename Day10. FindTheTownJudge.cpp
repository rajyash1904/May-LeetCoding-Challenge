/*

 Find the Town Judge

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
1. Everybody (except for the town judge) trusts the town judge.
2. There is exactly one person that satisfies properties 1 and 2.
3. You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Note:

1. 1 <= N <= 1000
2. trust.length <= 10000
3. trust[i] are all different
4. trust[i][0] != trust[i][1]
5. 1 <= trust[i][0], trust[i][1] <= N

*/

//solution1 Space:O(N^2) 

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {  
        vector<bool> vis(N,true);
        vector<vector<int>> arr(N);
        for(int i=0;i<trust.size();i++){
            arr[trust[i][1]-1].push_back(trust[i][0]);
            vis[trust[i][0]-1]=false;
        }
        for(int i=0;i<N;i++){
            
            if(arr[i].size()==(N-1) && vis[i]==true) return i+1;
        }
        return -1;
      }
  };
  
 
 //solution 2 space: O(N)
 
 class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {     
        vector<pair<int,int>>ans(N+1,{0,0});
        for(int i=0;i<trust.size();i++)
        {
            ans[trust[i][0]].first++;
            ans[trust[i][1]].second++;
        }
        for(int i=1;i<N+1;i++)
        {
            if(ans[i].first==0&&ans[i].second==N-1)
                return i;
        }
        return -1;
    }
};
        
