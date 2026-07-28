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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int a=height(root->left);
        int b=height(root->right);
        int d=max(a,b);
        return 1+d;
    }
    bool solve(TreeNode* root){
        if(!root){
            return true;
        }
        int a=height(root->left);
        int b=height(root->right);
        if(abs(a-b)>1){
            return false;
        }
        bool a1=solve(root->left);
        bool a2=solve(root->right);
        return a1&&a2;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};
