/*

Cousins In Binary Tree

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:
https://assets.leetcode.com/uploads/2019/02/12/q1248-01.png

Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:
https://assets.leetcode.com/uploads/2019/02/12/q1248-02.png

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:

https://assets.leetcode.com/uploads/2019/02/13/q1248-03.png

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

1. The number of nodes in the tree will be between 2 and 100.
2. Each node has a unique integer value from 1 to 100.

*/

//Solution approach: use Breadth First search checking if x and y have same parent or not if yes return false.
//                   otherwise if x and y are in same level return true.

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        TreeNode* i;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int n=q.size();
            count=0;
            while(n){
                
                i=q.front();
                if(i->val==x || i->val==y){
                    count++;
                }
                q.pop();
                if(i->left!=NULL && i->right!=NULL){
                    if(i->left->val==x && i->right->val==y) return false;
                    if(i->left->val==y && i->right->val==x) return false;    
                }
            
                if(i->left) q.push(i->left);
                if(i->right) q.push(i->right);
                n--;
            }
            if(count==2){
                return true;
            }
        }
        return false;
    }
};
