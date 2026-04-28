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
    int traversal(TreeNode* root, int &ans){
        if (root == NULL) return 0;

        int left=0, right =0;
        left = (root->left != NULL) ? 1+traversal(root->left, ans):0;
        right = (root->right != NULL) ? 1+ traversal(root->right, ans) :0;
        ans = max(ans, left+right);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0;
        traversal(root, ans);
        return ans;
    }
};
