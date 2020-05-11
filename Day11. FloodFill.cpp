/*

Flood Fill

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, 
"flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the 
same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the
starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

1. The length of image and image[0] will be in the range [1, 50].
2. The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
3. The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
   Hide Hint #1  
Write a recursive function that paints the pixel if it's the correct color, then recurses on neighboring pixels.

*/

class Solution {
public:
    void help(vector<vector<bool>>& vis,vector<vector<int>>& image, int x, int y, int k,int t){
        if(x<0 || x>=image.size() || y<0 || y>=image[x].size()){
            return;
        }
        if(vis[x][y]==true) return;
        if(image[x][y]==t){ 
            image[x][y]=k;
            vis[x][y]=true;
            help(vis,image,x,y+1,k,t);
            help(vis,image,x+1,y,k,t);
            help(vis,image,x-1,y,k,t);
            help(vis,image,x,y-1,k,t);
            return;
         }
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc]==newColor) return image;
        vector<bool> curr(image[0].size(),false);
        vector<vector<bool>> vis(image.size(),curr);
        help(vis,image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};
