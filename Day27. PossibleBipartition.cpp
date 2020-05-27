/*

Possible Bipartition

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1. 1 <= N <= 2000
2. 0 <= dislikes.length <= 10000
3. 1 <= dislikes[i][j] <= N
4. dislikes[i][0] < dislikes[i][1]
5. There does not exist i != j for which dislikes[i] == dislikes[j].

*/

class Solution {
public:
    set <int> groups[2];
    bool dfs(int node, vector <int> graph[], int x)
    {    
        int aux = 1 - x;
        if(groups[aux].count(node)) return false;
        groups[x].insert(node);
        for(int i = 0; i < graph[node].size(); i++)
        {
            int u = graph[node][i];
            if(!groups[aux].count(u) && !dfs(u, graph, aux)) return false;
        }
        return true;
   }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
    {
         vector <int> graph[N + 1];
         for(int i = 0; i < dislikes.size(); i++)
         {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
         }
        
         for(int i = 1; i <= N;i++)
         {
            if(!groups[0].count(i) && !groups[1].count(i))
            {
                if(!dfs(i, graph, 0)) return false;
            }
         }
        
         return true;
        
    }
};
