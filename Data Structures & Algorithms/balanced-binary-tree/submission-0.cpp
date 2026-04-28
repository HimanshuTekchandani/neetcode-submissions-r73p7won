/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int traversal(TreeNode* root){
        if(root == NULL) return 0;
        int left = traversal(root->left);
        int right = traversal(root->right);
        if (left == -1 || right ==-1)return -1;

        return (abs(left-right)<=1)? 1+max(left,right):-1; 

    }
    bool isBalanced(TreeNode* root) {
        int ans=traversal(root);
        return (ans == -1) ? false:true;
    }
};
