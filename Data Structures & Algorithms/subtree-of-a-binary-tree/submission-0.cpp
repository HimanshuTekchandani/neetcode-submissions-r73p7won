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
    bool subTree(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot ==NULL){
            return true;
        }
        if(root==NULL || subRoot ==NULL)return false;

        if(root->val != subRoot->val)return false;
        bool left= subTree(root->left, subRoot->left);
        if(!left)return left;
        bool right = subTree(root->right, subRoot->right);
        if(!right)return right;
        return true;


    }
    bool traversal(TreeNode* root, TreeNode* subRoot){
        if(root==NULL)return false;

        if(root->val == subRoot->val){
            bool eq = subTree(root, subRoot);
            if(eq)return eq;
        }
        bool left = traversal(root->left, subRoot);
        if(left)return left;
        bool right = traversal(root->right, subRoot);
        if(right)return right;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return traversal(root, subRoot);
    }
};
