/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
Check if these points make a straight line in the XY plane.

 

Example 1:

https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:

https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

1. 2 <= coordinates.length <= 1000
2. coordinates[i].length == 2
3. -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
4. coordinates contains no duplicate point.
   Hide Hint #1  
If there're only 2 points, return true.
 
   Hide Hint #2  
Check if all other points lie on the line defined by the first 2 points.
   
   Hide Hint #3  
Use cross product to check collinearity.

*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(coordinates.size()<=2) return true;
        double deno=(coordinates[1][1]-coordinates[0][1]);
        double numo=(coordinates[1][0]-coordinates[0][0]);
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        if(deno==0){
            for(int i=2;i<coordinates.size();i++){
                if(coordinates[i][1]!=coordinates[0][1]) return false;
            }
        }else if(numo==0){
            for(int i=2;i<coordinates.size();i++){
                if(coordinates[i][0]!=coordinates[0][0]) return false;
            }
        }else{
            double m=numo/deno;
            double curr;
            for(int i=2;i<coordinates.size();i++){
                curr=(double)(coordinates[i][0]-x1)/(double)(coordinates[i][1]-y1);
                if(curr!=m) return false;
            }
         }   
        return true;
    }
};
