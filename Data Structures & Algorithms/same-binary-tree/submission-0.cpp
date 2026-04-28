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
    bool traversal(TreeNode* p, TreeNode* q){
        if (p== NULL && q==NULL){
            return true;
        }
        if(p == NULL || q== NULL){
            return false;
        }
        if(p->val != q->val)return false;
        bool left = traversal(p->left, q->left);
        if(!left)return left;
        bool right = traversal(p->right, q->right);
        if(!right)return right;

        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversal(p,q);
    }
};
